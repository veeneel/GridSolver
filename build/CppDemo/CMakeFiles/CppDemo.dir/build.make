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
include CppDemo/CMakeFiles/CppDemo.dir/depend.make

# Include the progress variables for this target.
include CppDemo/CMakeFiles/CppDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CppDemo/CMakeFiles/CppDemo.dir/flags.make

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o: CppDemo/CMakeFiles/CppDemo.dir/flags.make
CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o: ../CppDemo/SolverDemo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o"
	cd /home/vneel/Projects/GridSolver/build/CppDemo && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppDemo.dir/SolverDemo.cpp.o -c /home/vneel/Projects/GridSolver/CppDemo/SolverDemo.cpp

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppDemo.dir/SolverDemo.cpp.i"
	cd /home/vneel/Projects/GridSolver/build/CppDemo && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vneel/Projects/GridSolver/CppDemo/SolverDemo.cpp > CMakeFiles/CppDemo.dir/SolverDemo.cpp.i

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppDemo.dir/SolverDemo.cpp.s"
	cd /home/vneel/Projects/GridSolver/build/CppDemo && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vneel/Projects/GridSolver/CppDemo/SolverDemo.cpp -o CMakeFiles/CppDemo.dir/SolverDemo.cpp.s

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.requires:

.PHONY : CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.requires

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.provides: CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.requires
	$(MAKE) -f CppDemo/CMakeFiles/CppDemo.dir/build.make CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.provides.build
.PHONY : CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.provides

CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.provides.build: CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o


# Object files for target CppDemo
CppDemo_OBJECTS = \
"CMakeFiles/CppDemo.dir/SolverDemo.cpp.o"

# External object files for target CppDemo
CppDemo_EXTERNAL_OBJECTS =

CppDemo/CppDemo: CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o
CppDemo/CppDemo: CppDemo/CMakeFiles/CppDemo.dir/build.make
CppDemo/CppDemo: SharedLib/libSharedLib.so
CppDemo/CppDemo: CppDemo/CMakeFiles/CppDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vneel/Projects/GridSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CppDemo"
	cd /home/vneel/Projects/GridSolver/build/CppDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CppDemo/CMakeFiles/CppDemo.dir/build: CppDemo/CppDemo

.PHONY : CppDemo/CMakeFiles/CppDemo.dir/build

CppDemo/CMakeFiles/CppDemo.dir/requires: CppDemo/CMakeFiles/CppDemo.dir/SolverDemo.cpp.o.requires

.PHONY : CppDemo/CMakeFiles/CppDemo.dir/requires

CppDemo/CMakeFiles/CppDemo.dir/clean:
	cd /home/vneel/Projects/GridSolver/build/CppDemo && $(CMAKE_COMMAND) -P CMakeFiles/CppDemo.dir/cmake_clean.cmake
.PHONY : CppDemo/CMakeFiles/CppDemo.dir/clean

CppDemo/CMakeFiles/CppDemo.dir/depend:
	cd /home/vneel/Projects/GridSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vneel/Projects/GridSolver /home/vneel/Projects/GridSolver/CppDemo /home/vneel/Projects/GridSolver/build /home/vneel/Projects/GridSolver/build/CppDemo /home/vneel/Projects/GridSolver/build/CppDemo/CMakeFiles/CppDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CppDemo/CMakeFiles/CppDemo.dir/depend
