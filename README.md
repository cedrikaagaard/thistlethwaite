# Thistlethwaite's algorithm C++
A C++ implementation of a modified version of Thistlethwaite's four phase
Rubik'c cube solving algorithm.

## Building
This project uses C++17 standard features, including
`std::experimental::filesystem` as well as header only boost libraries.

Because of `std::experimental::filesystem`, the flag `-lstdc++fs` is necessary
when compiling with g++.

This project compiles successfully with g++ 7.3.0.

If your compiler supports C++17 and `-lstdc++fs`, the building process is very
simple.
```bash
mkdir build && cd build
cmake ..
make
```

This builds a static library `libthistlethwaite.a`

## Usage
To use this library, copy the header files found in the `lib/` directory as well
as `libthistlethwaite.a` (which will have to be linked) to your project.

### Cube representation
The cube representation is inspired by: https://github.com/muodov/kociemba

```
             |************|
             |*U1**U2**U3*|
             |************|
             |*U4**U5**U6*|
             |************|
             |*U7**U8**U9*|
             |************|
 ************|************|************|************
 *L1**L2**L3*|*F1**F2**F3*|*R1**R2**R3*|*B1**B2**B3*
 ************|************|************|************
 *L4**L5**L6*|*F4**F5**F6*|*R4**R5**R6*|*B4**B5**B6*
 ************|************|************|************
 *L7**L8**L9*|*F7**F8**F9*|*R7**R8**R9*|*B7**B8**B9*
 ************|************|************|************
             |************|
             |*D1**D2**D3*|
             |************|
             |*D4**D5**D6*|
             |************|
             |*D7**D8**D9*|
             |************|
```

String representation: U1, U2, ..., U9, R1, R2, ..., R9...
String representation: UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB

### Generating tables
Thistlethwaite's algorithm uses lookup tables that needs to be generated
before the algorithm can be executed.

Generating these tables takes a couple of minutes, but only has to be done once.
The tables will be stored under `~/.thistlethwaite`

```C++
#include "tablegen.hpp"
thistlethwaite::generate_tables();
```

### Rand
This library implements a function that generates random rotations, this
can be useful for scrambling a cube. The only argument of the function is
the number of rotations.
```C++
#include "rand.hpp"
std::cout << thistlethwaite::get_random_rotations(25) << std::endl;
```
`>>> rRBFlfUFbRUBUFDbrRLLDRdBL`

### Cube object

#### Initializing a cube object
A cube object can either be created by passing a string representation of a cube
to the constructor or by initializing a solved cube.

```C++
#include "cube.hpp"

thistlethwaite::cube cube("BWWBYWOGGYOOYRRYYWBOOWBOYGORRBBWBGYGRRWOOGYWBGRWYGBRGR"); // Defined cube state
thistlethwaite::cube cube;     // solved cube
```

#### Simulating rotations
The cube.rotate() method takes a string as argument which represents
the rotations in the following way:

`U = up, R = right, F = front, D = down, L = left & B = back` Upper case letters
represent clockwise rotations and lower case letters represent counter clockwise
rotations.

```C++
cube.rotate("RLf"); // Right clockwise, left clockwise and front counter clockwise.
```

#### Accessors
This library implements methods for accessing single stickers on the cube,
both by supplying a string as defined in the cube representation subtitle and
by its internal representation. (The cube is represented by `[6][3][3]` internally.)

```C++
cube.get("U5"); // Requests the center sticker on the upper side of the cube.
cube.get(0, 1, 1); // Does the same as above.
```

#### Output
`cube.print()` prints a nicely formatted representation of the cube.

### Executing Thistlethwaite's algorithm
The thistlethwaite::solve()``method can be called either with a cube object or
a cube string representation as argument. The method will return a string
representing the rotations that will solve the cube.

Before `thistlethwaite::solve()` is called, the tables needs to be initialized
by calling `thistlethwaite::init_tables()` which will read the tables into memory.
The tables are rather large, so this may take up to about a minute. The memory used
by the tables can be deallocated with `thistlethwaite::deallocate_tables()`.

```C++
thistlethwaite::init_tables();
thistlethwaite::solve(cube);
thistlethwaite::deallocate_tables();
```

## Full example program
```C++
#include <iostream>
#include "cube.hpp"
#include "solver.hpp"
#include "tablegen.hpp"

int main() {
    // Could be moved to a separate program
    thistlethwaite::generate_tables();
    thistlethwaite::init_tables();
    thistlethwaite::cube cube("BWWBYWOGGYOOYRRYYWBOOWBOYGORRBBWBGYGRRWOOGYWBGRWYGBRGR");
    std::cout << thistlethwaite::solve(cube) << std::endl;
    return 0;
}
```

`>>> RlUfbblrr`