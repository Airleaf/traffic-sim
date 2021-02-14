#!/usr/bin/python3
#
# This script is used for custom compilation scripts with selected
# modules in order to achieve a selected enviroment for the running
# code. This is done using the test.json file located in every test.
#
# The first argument is the name of the test enviroment, being the 
# folder name where test.json is located.
#

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
    sh(f'g++ -o {args.test}/{args.test} {args.test}/{cfg["main"]} {" ".join(object_files)}')

    # Execute
    os.chdir(f'./{args.test}')
    sh(f'./{args.test}')


if __name__ == "__main__":
    main()