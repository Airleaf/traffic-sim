<p align="center">
    <img height=100 src="https://github.com/Airleaf/traffic-sim/blob/main/.github/traffic-sim.png?raw=true"><br>
    <img src="https://img.shields.io/github/last-commit/airleaf/traffic-sim?label=Last%20commit&style=flat-square">
    <img src="https://img.shields.io/tokei/lines/github/airleaf/traffic-sim?label=Total%20lines&style=flat-square">
    <img src="https://img.shields.io/github/contributors/airleaf/traffic-sim?label=Contributors&style=flat-square">
    <img src="https://img.shields.io/github/issues/airleaf/traffic-sim?label=Issues&style=flat-square">
</p>
<hr>

This is a traffic simulator written mostly in C++ using SFML. 

<!-- ---------- SECTOR ---------- -->

## Contributing

### Basic rules

- Any development should **happen on its own branch**, and then should be merged to `beta`, every now
  and again when the code seems stable we merge to `main`.
- All commits to `main` should keep a **strict code style**, in order to increase readability and compatibility
  with the rest of the code.
- Your code should be **organized and tested** before merging to `beta`.
- All code will be made cross-compatible on Linux & Windows systems.
- The code style we chose is based on the official C++ style, with a couple of personal modifications.

### Indents
We use 4-space indents, just the normal amount.

### Functions
All functions and methods should have atleast 1 sentence describing what is does like shown below. 
```cpp
/* This is a comment about what the function does and generally what is should 
 * return. 
 * @param stuff - random string
 */

void func(std::string &stuff);
```

### Pointers
The stars and ampersands generally should be located closer to the variable name, not the type. 
```cpp
int *pointer;
Foo::Bar *fbar;
void foo(uint *nums);

void bar(std::string &str);


```

### Naming
If you don't see the thing you want in here, that means you can name it anyway you want.
<table>
<tr>
    <th>Field</th>
    <th>Convention</th>
</tr>
<tr>
    <td>Local variable</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>Pointer variable</td>
    <td><code>foo_bar</code> / <code>pfoo_bar</code></td>
</tr>
<tr>
    <td>Local variable</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>Global variable</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>Constant</td>
    <td><code>FOO_BAR</code></td>
</tr>
<tr>
    <td>Header guard</td>
    <td><code>FOO_BAR_H</code></td>
</tr>
<tr>
    <td>Function</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>Class</td>
    <td><code>FooBar</code></td>
</tr>
<tr>
    <td>Class method</td>
    <td><code>FooBar</code></td>
</tr>
<tr>

    <td>Class methods that returns a bool</td>

    <td>Class methods that return a bool value</td>

    <td><code>IsFooBar</code></td>
</tr>
<tr>
    <td>Class method - getter</td>
    <td><code>GetFooBar</code></td>
</tr>
<tr>
    <td>Class method - setter</td>
    <td><code>SetFooBar</code></td>
</tr>
<tr>
    <td>Class member</td>
    <td><code>fooBar</code> / <code>mFooBar</code></td>
</tr>
<tr>
    <td>Header / source file</td>
    <td><code>Foobar.h</code> / <code>Foobar.cpp</code></td>
</tr>
<tr>
    <td>C constant</td>
    <td><code>T_FOO_BAR</code></td>
</tr>
<tr>
    <td>C header guard</td>
    <td><code>T_FOO_BAR_H_</code></td>
</tr>
<tr>
    <td>C function</td>
    <td><code>t_foo_bar</code></td>
</tr>
<tr>
    <td>C local variable</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>C global variable</td>
    <td><code>t_foo_bar</code></td>
</tr>
<tr>
    <td>C struct / union</td>
    <td><code>TFooBar</code></td>
</tr>
<tr>
    <td>C struct member</td>
    <td><code>foo_bar</code></td>
</tr>
<tr>
    <td>C enum</td>
    <td><code>TFooBar_Enum</code></td>
</tr>
<tr>
    <td>C enum member</td>
    <td><code>TFooBar_Type</code></td>
</tr>
<tr>
    <td>C header / source</td>
    <td><code>cfoobar.h</code> / <code>cfoobar.c</code></td>
</tr>
</table>

### C
Because some code can be written in C, it deserves its own area.
- All C code global fields, constants and functions should start with either `T_` or `t_`. This naming convention
  is reserved for C code only.
- Every C header should have a C++ wrapper that is easy to use.

<!-- ---------- SECTOR ---------- -->

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
