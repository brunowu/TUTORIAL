cmake_minimum_required(VERSION 2.8)

add_executable(test.exe main.c)

find_package(MPI REQUIRED)


target_link_libraries(test.exe PRIVATE ${MPI_C_LIBRARIES})

target_include_directories(test.exe PRIVATE ${MPI_C_INCLUDE_PATH}) 
