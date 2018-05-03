aux_source_directory(. DIR_WORLD_SRC)

add_library(world_lib ${DIR_WORLD_SRC})

install(TARGETS world_lib DESTINATION lib)

install(FILES world.h DESTINATION include)

