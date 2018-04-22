find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.1)

# Static library
project(thistlethwaite)
ADD_LIBRARY(
		thistlethwaite STATIC lib/solver.hpp lib/tablegen.hpp
		src/headers/enums.hpp src/cpp/enums.cpp src/cpp/cuberotation.cpp
		src/cpp/acceccors.cpp src/cpp/constructors.cpp src/cpp/output.cpp
		src/cpp/stageid.cpp src/headers/tableutil.hpp src/cpp/tablegen.cpp
		src/cpp/tableutil.cpp src/cpp/solver.cpp lib/rand.hpp src/cpp/rand.cpp
		src/cpp/stagecheck.cpp
)

target_include_directories(thistlethwaite PRIVATE lib src/headers)
target_link_libraries(thistlethwaite ${Boost_LIBRARIES})