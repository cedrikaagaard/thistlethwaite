cmake_minimum_required(VERSION 3.10)
project(thistlethwaite)

set(CMAKE_CXX_STANDARD 11)


find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(thistlethwaite main.cpp cubelib.hpp enumerations/enumconversions.cpp cube_representation/constructors.cpp cube_representation/accessors.cpp cube_representation/output.cpp cube_representation/rotation.cpp cube_hashing/general_hash.cpp cube_hashing/g0_hash.cpp cube_hashing/g1_hash.cpp cube_hashing/g2_hash.cpp cube_hashing/g3_hash.cpp cube_hashing/checker.cpp tables/util.cpp tables/generate.cpp tables/read.cpp solver.cpp enumerations/rand.cpp)

target_link_libraries(thistlethwaite ${Boost_LIBRARIES})

