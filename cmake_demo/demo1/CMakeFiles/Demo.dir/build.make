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
CMAKE_SOURCE_DIR = /home/xinzhewu/workstations/cmake_demo/demo1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xinzhewu/workstations/cmake_demo/demo1

# Include any dependencies generated for this target.
include CMakeFiles/Demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Demo.dir/flags.make

CMakeFiles/Demo.dir/main.o: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/main.o: main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xinzhewu/workstations/cmake_demo/demo1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Demo.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Demo.dir/main.o -c /home/xinzhewu/workstations/cmake_demo/demo1/main.cc

CMakeFiles/Demo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xinzhewu/workstations/cmake_demo/demo1/main.cc > CMakeFiles/Demo.dir/main.i

CMakeFiles/Demo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xinzhewu/workstations/cmake_demo/demo1/main.cc -o CMakeFiles/Demo.dir/main.s

CMakeFiles/Demo.dir/main.o.requires:
.PHONY : CMakeFiles/Demo.dir/main.o.requires

CMakeFiles/Demo.dir/main.o.provides: CMakeFiles/Demo.dir/main.o.requires
	$(MAKE) -f CMakeFiles/Demo.dir/build.make CMakeFiles/Demo.dir/main.o.provides.build
.PHONY : CMakeFiles/Demo.dir/main.o.provides

CMakeFiles/Demo.dir/main.o.provides.build: CMakeFiles/Demo.dir/main.o
.PHONY : CMakeFiles/Demo.dir/main.o.provides.build

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/main.o"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

Demo: CMakeFiles/Demo.dir/main.o
Demo: CMakeFiles/Demo.dir/build.make
Demo: CMakeFiles/Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Demo.dir/build: Demo
.PHONY : CMakeFiles/Demo.dir/build

CMakeFiles/Demo.dir/requires: CMakeFiles/Demo.dir/main.o.requires
.PHONY : CMakeFiles/Demo.dir/requires

CMakeFiles/Demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Demo.dir/clean

CMakeFiles/Demo.dir/depend:
	cd /home/xinzhewu/workstations/cmake_demo/demo1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xinzhewu/workstations/cmake_demo/demo1 /home/xinzhewu/workstations/cmake_demo/demo1 /home/xinzhewu/workstations/cmake_demo/demo1 /home/xinzhewu/workstations/cmake_demo/demo1 /home/xinzhewu/workstations/cmake_demo/demo1/CMakeFiles/Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Demo.dir/depend

