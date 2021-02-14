#!/usr/bin/python3
import argparse
import json
import os

sh = os.system

# Argument parser
parser = argparse.ArgumentParser()
parser.add_argument('test', type=str, help='Name of the test directory found in tests/')

args = parser.parse_args()


def stop(msg):
    # Print the given message and exit the program
    print(msg)
    quit()


def main():
    # Check if file exists
    if not os.path.isdir(args.test):
        stop(f'Cannot find \'{args.test}\' or it\'s not a directory')

    # Read test configuration
    try:
        with open(f'{args.test}/test.json') as f:
            cfg = json.load(f)
    except FileNotFoundError:
        stop('All tests are required to have a \'test.json\' file')

    if 'main' not in cfg:
        stop('\'main\' field not found in test.json file')
    if 'cpp-sources' not in cfg:
        stop('\'cpp-sources\' field not found in test.json file')

    object_files = []

    # Compile
    for src in cfg['cpp-sources']:
        sh(f'g++ -c -o __out__/{src}.o ../src/{src}')
        object_files.append(f'__out__/{src}.o')

    for src in cfg['c-sources']:
        sh(f'gcc -c -o __out__/{src}.o ../src/{src}')
        object_files.append(f'__out__/{src}.o')

    # Link
    sh(f'g++ -o __out__/{args.test} {args.test}/{cfg["main"]} {" ".join(object_files)}')

    # Execute
    sh(f'__out__/{args.test} > __out__/__stdout__')


if __name__ == "__main__":
    main()
