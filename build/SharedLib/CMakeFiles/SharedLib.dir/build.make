# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vneel/Projects/GridSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vneel/Projects/GridSolver/build

# Include any dependencies generated for this target.
include SharedLib/CMakeFiles/SharedLib.dir/depend.make

# Include the progress variables for this target.
include SharedLib/CMakeFiles/SharedLib.dir/progress.make

# Include the compile flags for this target's objects.
include SharedLib/CMakeFiles/SharedLib.dir/flags.make

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o: SharedLib/CMakeFiles/SharedLib.dir/flags.make
SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o: ../SharedLib/SharedLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SharedLib.dir/SharedLib.cpp.o -c /home/vneel/Projects/GridSolver/SharedLib/SharedLib.cpp

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedLib.dir/SharedLib.cpp.i"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vneel/Projects/GridSolver/SharedLib/SharedLib.cpp > CMakeFiles/SharedLib.dir/SharedLib.cpp.i

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedLib.dir/SharedLib.cpp.s"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vneel/Projects/GridSolver/SharedLib/SharedLib.cpp -o CMakeFiles/SharedLib.dir/SharedLib.cpp.s

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.requires:

.PHONY : SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.requires

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.provides: SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.requires
	$(MAKE) -f SharedLib/CMakeFiles/SharedLib.dir/build.make SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.provides.build
.PHONY : SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.provides

SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.provides.build: SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o


# Object files for target SharedLib
SharedLib_OBJECTS = \
"CMakeFiles/SharedLib.dir/SharedLib.cpp.o"

# External object files for target SharedLib
SharedLib_EXTERNAL_OBJECTS =

SharedLib/libSharedLib.so: SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o
SharedLib/libSharedLib.so: SharedLib/CMakeFiles/SharedLib.dir/build.make
SharedLib/libSharedLib.so: SharedLib/CMakeFiles/SharedLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSharedLib.so"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SharedLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SharedLib/CMakeFiles/SharedLib.dir/build: SharedLib/libSharedLib.so

.PHONY : SharedLib/CMakeFiles/SharedLib.dir/build

SharedLib/CMakeFiles/SharedLib.dir/requires: SharedLib/CMakeFiles/SharedLib.dir/SharedLib.cpp.o.requires

.PHONY : SharedLib/CMakeFiles/SharedLib.dir/requires

SharedLib/CMakeFiles/SharedLib.dir/clean:
	cd /home/vneel/Projects/GridSolver/build/SharedLib && $(CMAKE_COMMAND) -P CMakeFiles/SharedLib.dir/cmake_clean.cmake
.PHONY : SharedLib/CMakeFiles/SharedLib.dir/clean

SharedLib/CMakeFiles/SharedLib.dir/depend:
	cd /home/vneel/Projects/GridSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vneel/Projects/GridSolver /home/vneel/Projects/GridSolver/SharedLib /home/vneel/Projects/GridSolver/build /home/vneel/Projects/GridSolver/build/SharedLib /home/vneel/Projects/GridSolver/build/SharedLib/CMakeFiles/SharedLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SharedLib/CMakeFiles/SharedLib.dir/depend

