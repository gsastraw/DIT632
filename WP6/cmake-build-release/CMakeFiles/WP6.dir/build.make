# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/juliavankirk/Desktop/DIT632/WP6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/WP6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WP6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WP6.dir/flags.make

CMakeFiles/WP6.dir/main.cpp.o: CMakeFiles/WP6.dir/flags.make
CMakeFiles/WP6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WP6.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WP6.dir/main.cpp.o -c /Users/juliavankirk/Desktop/DIT632/WP6/main.cpp

CMakeFiles/WP6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WP6.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/juliavankirk/Desktop/DIT632/WP6/main.cpp > CMakeFiles/WP6.dir/main.cpp.i

CMakeFiles/WP6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WP6.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/juliavankirk/Desktop/DIT632/WP6/main.cpp -o CMakeFiles/WP6.dir/main.cpp.s

# Object files for target WP6
WP6_OBJECTS = \
"CMakeFiles/WP6.dir/main.cpp.o"

# External object files for target WP6
WP6_EXTERNAL_OBJECTS =

WP6: CMakeFiles/WP6.dir/main.cpp.o
WP6: CMakeFiles/WP6.dir/build.make
WP6: CMakeFiles/WP6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WP6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WP6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WP6.dir/build: WP6

.PHONY : CMakeFiles/WP6.dir/build

CMakeFiles/WP6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WP6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WP6.dir/clean

CMakeFiles/WP6.dir/depend:
	cd /Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/juliavankirk/Desktop/DIT632/WP6 /Users/juliavankirk/Desktop/DIT632/WP6 /Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release /Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release /Users/juliavankirk/Desktop/DIT632/WP6/cmake-build-release/CMakeFiles/WP6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WP6.dir/depend

