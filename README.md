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

### Initializing a cube object
