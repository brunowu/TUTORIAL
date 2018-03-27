aux_source_directory(. DIR_HELLO_SRC)

add_library(hello_lib ${DIR_HELLO_SRC})

install(TARGETS hello_lib DESTINATION lib)

install(FILES hello.h DESTINATION include)
