cmake_minimum_required(VERSION 2.8)

project(Demo)

message([STATUS] "Root File is ${Demo_SOURCE_DIR}")

find_package(MPI REQUIRED)

if(NOT MPI_CXX_FOUND)
	message([FATAL_ERROR] "MPI CXX compiler was not found and is required ")
endif()

SET(CMAKE_CXX_COMPILER mpicxx)

add_subdirectory(hello)

add_subdirectory(world)

add_subdirectory(test)

enable_testing()

set(PROCS 2)

add_test(test_1 ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${PROCS} ./test/main)


