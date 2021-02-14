# cte

CTE provides a simple C/C++ testing enviroment, which is done by defining a JSON configuration file and compiling 
the source files into a closed enviroment for testing. This is created to be easy to use, so each 'test' unit
is found in a seperate directory. As you can see from the `log` example, a single test is just a directory
with a `test.json` configuration file.

## Setup

- **Before running a test**, be sure to run `setup.sh` *(this will be automated in the future)*, to create the required
  directories.
- Create a directory with the topic you're testing, like `car` or `lang`.
- Create a `.cpp` file with your main function called `main.cpp` and place it in the test directory.
- Create a `test.json` inside the test directory, here is a simple example:

```json
{
    "version": 1,
    "main": "main.cpp",
    "cpp-sources": [
        "Car.cpp"
    ]
}
```
This will compile main.cpp including `Car.cpp` from the root `src/` directory. Be sure to list all dependencies here,
or else this will not work as this is a closed enviroment.

## Run

After that, run this to compile & link the `car` unit test.
```
python3 cte.py car
```
This will create some stuff in the `__out__` directory, and will run a compiled executable in the test directory, 
so all relative files will be dumped there, in your own enviroment.
