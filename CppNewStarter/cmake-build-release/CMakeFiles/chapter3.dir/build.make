# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /tmp/tmp.wViq5ocIbb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.wViq5ocIbb/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/chapter3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chapter3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chapter3.dir/flags.make

CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o: CMakeFiles/chapter3.dir/flags.make
CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o: ../follow_cpp_primer_5th/chapter3/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.wViq5ocIbb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o -c /tmp/tmp.wViq5ocIbb/follow_cpp_primer_5th/chapter3/Main.cpp

CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.wViq5ocIbb/follow_cpp_primer_5th/chapter3/Main.cpp > CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.i

CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.wViq5ocIbb/follow_cpp_primer_5th/chapter3/Main.cpp -o CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.s

# Object files for target chapter3
chapter3_OBJECTS = \
"CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o"

# External object files for target chapter3
chapter3_EXTERNAL_OBJECTS =

chapter3: CMakeFiles/chapter3.dir/follow_cpp_primer_5th/chapter3/Main.cpp.o
chapter3: CMakeFiles/chapter3.dir/build.make
chapter3: CMakeFiles/chapter3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.wViq5ocIbb/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chapter3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chapter3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chapter3.dir/build: chapter3

.PHONY : CMakeFiles/chapter3.dir/build

CMakeFiles/chapter3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chapter3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chapter3.dir/clean

CMakeFiles/chapter3.dir/depend:
	cd /tmp/tmp.wViq5ocIbb/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.wViq5ocIbb /tmp/tmp.wViq5ocIbb /tmp/tmp.wViq5ocIbb/cmake-build-release /tmp/tmp.wViq5ocIbb/cmake-build-release /tmp/tmp.wViq5ocIbb/cmake-build-release/CMakeFiles/chapter3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chapter3.dir/depend

