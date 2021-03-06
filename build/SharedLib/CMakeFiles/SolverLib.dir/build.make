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
include SharedLib/CMakeFiles/SolverLib.dir/depend.make

# Include the progress variables for this target.
include SharedLib/CMakeFiles/SolverLib.dir/progress.make

# Include the compile flags for this target's objects.
include SharedLib/CMakeFiles/SolverLib.dir/flags.make

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o: SharedLib/CMakeFiles/SolverLib.dir/flags.make
SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o: ../SharedLib/SolverLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SolverLib.dir/SolverLib.cpp.o -c /home/vneel/Projects/GridSolver/SharedLib/SolverLib.cpp

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SolverLib.dir/SolverLib.cpp.i"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vneel/Projects/GridSolver/SharedLib/SolverLib.cpp > CMakeFiles/SolverLib.dir/SolverLib.cpp.i

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SolverLib.dir/SolverLib.cpp.s"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vneel/Projects/GridSolver/SharedLib/SolverLib.cpp -o CMakeFiles/SolverLib.dir/SolverLib.cpp.s

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.requires:

.PHONY : SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.requires

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.provides: SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.requires
	$(MAKE) -f SharedLib/CMakeFiles/SolverLib.dir/build.make SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.provides.build
.PHONY : SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.provides

SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.provides.build: SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o


# Object files for target SolverLib
SolverLib_OBJECTS = \
"CMakeFiles/SolverLib.dir/SolverLib.cpp.o"

# External object files for target SolverLib
SolverLib_EXTERNAL_OBJECTS =

SharedLib/libSolverLib.so: SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o
SharedLib/libSolverLib.so: SharedLib/CMakeFiles/SolverLib.dir/build.make
SharedLib/libSolverLib.so: SharedLib/CMakeFiles/SolverLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSolverLib.so"
	cd /home/vneel/Projects/GridSolver/build/SharedLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SolverLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SharedLib/CMakeFiles/SolverLib.dir/build: SharedLib/libSolverLib.so

.PHONY : SharedLib/CMakeFiles/SolverLib.dir/build

SharedLib/CMakeFiles/SolverLib.dir/requires: SharedLib/CMakeFiles/SolverLib.dir/SolverLib.cpp.o.requires

.PHONY : SharedLib/CMakeFiles/SolverLib.dir/requires

SharedLib/CMakeFiles/SolverLib.dir/clean:
	cd /home/vneel/Projects/GridSolver/build/SharedLib && $(CMAKE_COMMAND) -P CMakeFiles/SolverLib.dir/cmake_clean.cmake
.PHONY : SharedLib/CMakeFiles/SolverLib.dir/clean

SharedLib/CMakeFiles/SolverLib.dir/depend:
	cd /home/vneel/Projects/GridSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vneel/Projects/GridSolver /home/vneel/Projects/GridSolver/SharedLib /home/vneel/Projects/GridSolver/build /home/vneel/Projects/GridSolver/build/SharedLib /home/vneel/Projects/GridSolver/build/SharedLib/CMakeFiles/SolverLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SharedLib/CMakeFiles/SolverLib.dir/depend

