# CMake version
cmake_minimum_required (VERSION 2.0)

#Project Info
project (Demo4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

option (USE_MYMATH
	   "Use provided math implementation" OFF)

#option (USE_MYMATH
#           "Use provided math implementation" ON)

if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

#add SOURCE VARIABLE
aux_source_directory(. DIR_SRCS)

#Executable File
add_executable (Demo ${DIR_SRCS})

#add link lib
target_link_libraries(Demo ${EXTRA_LIBS})

