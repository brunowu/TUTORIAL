# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xinzhewu/workstations/cmake_demo/demo5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xinzhewu/workstations/cmake_demo/demo5

# Include any dependencies generated for this target.
include math/CMakeFiles/MathFunctions.dir/depend.make

# Include the progress variables for this target.
include math/CMakeFiles/MathFunctions.dir/progress.make

# Include the compile flags for this target's objects.
include math/CMakeFiles/MathFunctions.dir/flags.make

math/CMakeFiles/MathFunctions.dir/MathFunctions.o: math/CMakeFiles/MathFunctions.dir/flags.make
math/CMakeFiles/MathFunctions.dir/MathFunctions.o: math/MathFunctions.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xinzhewu/workstations/cmake_demo/demo5/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object math/CMakeFiles/MathFunctions.dir/MathFunctions.o"
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MathFunctions.dir/MathFunctions.o -c /home/xinzhewu/workstations/cmake_demo/demo5/math/MathFunctions.cc

math/CMakeFiles/MathFunctions.dir/MathFunctions.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MathFunctions.dir/MathFunctions.i"
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xinzhewu/workstations/cmake_demo/demo5/math/MathFunctions.cc > CMakeFiles/MathFunctions.dir/MathFunctions.i

math/CMakeFiles/MathFunctions.dir/MathFunctions.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MathFunctions.dir/MathFunctions.s"
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xinzhewu/workstations/cmake_demo/demo5/math/MathFunctions.cc -o CMakeFiles/MathFunctions.dir/MathFunctions.s

math/CMakeFiles/MathFunctions.dir/MathFunctions.o.requires:
.PHONY : math/CMakeFiles/MathFunctions.dir/MathFunctions.o.requires

math/CMakeFiles/MathFunctions.dir/MathFunctions.o.provides: math/CMakeFiles/MathFunctions.dir/MathFunctions.o.requires
	$(MAKE) -f math/CMakeFiles/MathFunctions.dir/build.make math/CMakeFiles/MathFunctions.dir/MathFunctions.o.provides.build
.PHONY : math/CMakeFiles/MathFunctions.dir/MathFunctions.o.provides

math/CMakeFiles/MathFunctions.dir/MathFunctions.o.provides.build: math/CMakeFiles/MathFunctions.dir/MathFunctions.o
.PHONY : math/CMakeFiles/MathFunctions.dir/MathFunctions.o.provides.build

# Object files for target MathFunctions
MathFunctions_OBJECTS = \
"CMakeFiles/MathFunctions.dir/MathFunctions.o"

# External object files for target MathFunctions
MathFunctions_EXTERNAL_OBJECTS =

math/libMathFunctions.a: math/CMakeFiles/MathFunctions.dir/MathFunctions.o
math/libMathFunctions.a: math/CMakeFiles/MathFunctions.dir/build.make
math/libMathFunctions.a: math/CMakeFiles/MathFunctions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libMathFunctions.a"
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && $(CMAKE_COMMAND) -P CMakeFiles/MathFunctions.dir/cmake_clean_target.cmake
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MathFunctions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
math/CMakeFiles/MathFunctions.dir/build: math/libMathFunctions.a
.PHONY : math/CMakeFiles/MathFunctions.dir/build

math/CMakeFiles/MathFunctions.dir/requires: math/CMakeFiles/MathFunctions.dir/MathFunctions.o.requires
.PHONY : math/CMakeFiles/MathFunctions.dir/requires

math/CMakeFiles/MathFunctions.dir/clean:
	cd /home/xinzhewu/workstations/cmake_demo/demo5/math && $(CMAKE_COMMAND) -P CMakeFiles/MathFunctions.dir/cmake_clean.cmake
.PHONY : math/CMakeFiles/MathFunctions.dir/clean

math/CMakeFiles/MathFunctions.dir/depend:
	cd /home/xinzhewu/workstations/cmake_demo/demo5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xinzhewu/workstations/cmake_demo/demo5 /home/xinzhewu/workstations/cmake_demo/demo5/math /home/xinzhewu/workstations/cmake_demo/demo5 /home/xinzhewu/workstations/cmake_demo/demo5/math /home/xinzhewu/workstations/cmake_demo/demo5/math/CMakeFiles/MathFunctions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : math/CMakeFiles/MathFunctions.dir/depend

