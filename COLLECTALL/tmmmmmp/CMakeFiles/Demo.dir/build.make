# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jason/Code-Table/tmmmmmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jason/Code-Table/tmmmmmp

# Include any dependencies generated for this target.
include CMakeFiles/Demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Demo.dir/flags.make

CMakeFiles/Demo.dir/externall.cpp.o: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/externall.cpp.o: externall.cpp
CMakeFiles/Demo.dir/externall.cpp.o: CMakeFiles/Demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jason/Code-Table/tmmmmmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Demo.dir/externall.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Demo.dir/externall.cpp.o -MF CMakeFiles/Demo.dir/externall.cpp.o.d -o CMakeFiles/Demo.dir/externall.cpp.o -c /home/jason/Code-Table/tmmmmmp/externall.cpp

CMakeFiles/Demo.dir/externall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo.dir/externall.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jason/Code-Table/tmmmmmp/externall.cpp > CMakeFiles/Demo.dir/externall.cpp.i

CMakeFiles/Demo.dir/externall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo.dir/externall.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jason/Code-Table/tmmmmmp/externall.cpp -o CMakeFiles/Demo.dir/externall.cpp.s

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/externall.cpp.o"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

Demo: CMakeFiles/Demo.dir/externall.cpp.o
Demo: CMakeFiles/Demo.dir/build.make
Demo: CMakeFiles/Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jason/Code-Table/tmmmmmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Demo.dir/build: Demo
.PHONY : CMakeFiles/Demo.dir/build

CMakeFiles/Demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Demo.dir/clean

CMakeFiles/Demo.dir/depend:
	cd /home/jason/Code-Table/tmmmmmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason/Code-Table/tmmmmmp /home/jason/Code-Table/tmmmmmp /home/jason/Code-Table/tmmmmmp /home/jason/Code-Table/tmmmmmp /home/jason/Code-Table/tmmmmmp/CMakeFiles/Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Demo.dir/depend

