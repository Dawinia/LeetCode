# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\JetBrains\apps\CLion\ch-0\191.6707.69\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\JetBrains\apps\CLion\ch-0\191.6707.69\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CodeBook\LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CodeBook\LeetCode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Array_TwoSum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Array_TwoSum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Array_TwoSum.dir/flags.make

CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.obj: CMakeFiles/Array_TwoSum.dir/flags.make
CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.obj: ../Array/TwoSum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CodeBook\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Array_TwoSum.dir\Array\TwoSum.cpp.obj -c E:\CodeBook\LeetCode\Array\TwoSum.cpp

CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CodeBook\LeetCode\Array\TwoSum.cpp > CMakeFiles\Array_TwoSum.dir\Array\TwoSum.cpp.i

CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CodeBook\LeetCode\Array\TwoSum.cpp -o CMakeFiles\Array_TwoSum.dir\Array\TwoSum.cpp.s

# Object files for target Array_TwoSum
Array_TwoSum_OBJECTS = \
"CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.obj"

# External object files for target Array_TwoSum
Array_TwoSum_EXTERNAL_OBJECTS =

Array_TwoSum.exe: CMakeFiles/Array_TwoSum.dir/Array/TwoSum.cpp.obj
Array_TwoSum.exe: CMakeFiles/Array_TwoSum.dir/build.make
Array_TwoSum.exe: CMakeFiles/Array_TwoSum.dir/linklibs.rsp
Array_TwoSum.exe: CMakeFiles/Array_TwoSum.dir/objects1.rsp
Array_TwoSum.exe: CMakeFiles/Array_TwoSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CodeBook\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Array_TwoSum.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Array_TwoSum.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Array_TwoSum.dir/build: Array_TwoSum.exe

.PHONY : CMakeFiles/Array_TwoSum.dir/build

CMakeFiles/Array_TwoSum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Array_TwoSum.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Array_TwoSum.dir/clean

CMakeFiles/Array_TwoSum.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CodeBook\LeetCode E:\CodeBook\LeetCode E:\CodeBook\LeetCode\cmake-build-debug E:\CodeBook\LeetCode\cmake-build-debug E:\CodeBook\LeetCode\cmake-build-debug\CMakeFiles\Array_TwoSum.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Array_TwoSum.dir/depend

