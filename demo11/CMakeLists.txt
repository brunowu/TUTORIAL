cmake_minimum_required(VERSION 2.8)

project(Demo)

message([STATUS] "Root File is ${Demo_SOURCE_DIR}")
find_package(MPI REQUIRED)
SET(CMAKE_CXX_COMPILER mpicxx)

add_subdirectory(hello)

add_subdirectory(world)

add_subdirectory(test)



