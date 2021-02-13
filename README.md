<p align="center">
    <img height=100 src="https://github.com/Airleaf/traffic-sim/blob/main/.github/traffic-sim.png?raw=true"><br>
    <img src="https://img.shields.io/github/last-commit/airleaf/traffic-sim?label=Last%20commit&style=flat-square">
    <img src="https://img.shields.io/tokei/lines/github/airleaf/traffic-sim?label=Total%20lines&style=flat-square">
    <img src="https://img.shields.io/github/contributors/airleaf/traffic-sim?label=Contributors&style=flat-square">
    <img src="https://img.shields.io/github/issues/airleaf/traffic-sim?label=Issues&style=flat-square">
</p>
<hr>

This is a traffic simulator written mostly in C++ using SFML. 

## Compilation
### Linux
Building is done with cmake, all you need is `libsfml-dev` installed on your system, and then run these commands:
```
mkdir build
cd build
cmake ..
make
```
These commands will generate a Makefile in the `build` folder, which you can then use from the root folder using:
```
make -C build/
```
