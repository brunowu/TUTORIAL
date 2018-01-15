# CMake version
cmake_minimum_required (VERSION 2.0)

#Project Info
project (Demo3)

#add SOURCE VARIABLE
aux_source_directory(. DIR_SRCS)

#add sub dir
add_subdirectory(math)

#Executable File
add_executable (Demo ${DIR_SRCS})

#add link lib
target_link_libraries(Demo MathFunctions)

