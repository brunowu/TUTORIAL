aux_source_directory(. DIR_LIB_SRCS)
add_library (MathFunctions ${DIR_LIB_SRCS})

install (TARGETS MathFunctions DESTINATION "libs")
install (FILES MathFunctions.h DESTINATION "include")

