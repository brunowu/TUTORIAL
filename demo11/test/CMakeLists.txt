aux_source_directory(. DIR_SRC)

add_executable(main ${DIR_SRC})

link_directories(${Demo_SOURCE_FILE}/${DIR_HELLO_SRC} ${Demo_SOURCE_FILE}/${DIR_WORLD_SRC})

target_link_libraries(main PRIVATE ${MPI_C_LIBRARIES} hello_lib world_lib)

target_include_directories(main PRIVATE ${MPI_C_INCLUDE_PATH}) 

