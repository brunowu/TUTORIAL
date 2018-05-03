# CMake version
cmake_minimum_required (VERSION 2.0)

#Project Info
project (Demo2)

#add SOURCE VARIABLE
aux_source_directory(. DIR_SRCS)

#Executable File
add_executable (Demo ${DIR_SRCS})

