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

### Generating tables
Thistlethwaite's algorithm uses lookup tables that needs to be generated
before the algorithm can be executed.

Generating these tables takes a couple of minutes, but only has to be done once.
The tables will be stored under `~/.thistlethwaite`

```C++
#include "tablegen.hpp"
thistlethwaite::generate_tables();
```

### Cube representation
// TODO: write representation README

### Cube object

#### Initializing a cube object
A cube object can either be created by passing a string representation of a cube
to the constructor or by initializing a solved cube.

```C++
#include "cube.hpp"

thistlethwaite::cube cube(""); // Defined cube state
thistlethwaite::cube cube;     // solved cube
```

#### Simulating rotations
The cube.rotate() method takes a string as argument which represents
the rotations in the following way:

U = up, R = right, F = front, D = down, L = left & B = back. Upper case letters
represent clockwise rotations and lower case letters represent counter clockwise
rotations.

```C++
cube.rotate("RLf"); // Simulates the rotations: right clockwise, left clockwise and
front counter clockwise.
```

#### Accessors
This library implements methods for accessing single stickers on the cube,
both by supplying a string as defined in the cube representation subtitle and
by its internal representation. (The cube is represented by `[6][3][3]` internally.)

```C++
cube.get("U5"); // Requests the center sticker on the upper side of the cube.
cube.get(0, 1, 1); // Does the same as above.
```