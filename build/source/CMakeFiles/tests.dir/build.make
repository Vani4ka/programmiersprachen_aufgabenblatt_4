# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build"

# Include any dependencies generated for this target.
include source/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/tests.dir/flags.make

source/CMakeFiles/tests.dir/testlist.cpp.o: source/CMakeFiles/tests.dir/flags.make
source/CMakeFiles/tests.dir/testlist.cpp.o: ../source/testlist.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/tests.dir/testlist.cpp.o"
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/testlist.cpp.o -c "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/source/testlist.cpp"

source/CMakeFiles/tests.dir/testlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/testlist.cpp.i"
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/source/testlist.cpp" > CMakeFiles/tests.dir/testlist.cpp.i

source/CMakeFiles/tests.dir/testlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/testlist.cpp.s"
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/source/testlist.cpp" -o CMakeFiles/tests.dir/testlist.cpp.s

source/CMakeFiles/tests.dir/testlist.cpp.o.requires:
.PHONY : source/CMakeFiles/tests.dir/testlist.cpp.o.requires

source/CMakeFiles/tests.dir/testlist.cpp.o.provides: source/CMakeFiles/tests.dir/testlist.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tests.dir/build.make source/CMakeFiles/tests.dir/testlist.cpp.o.provides.build
.PHONY : source/CMakeFiles/tests.dir/testlist.cpp.o.provides

source/CMakeFiles/tests.dir/testlist.cpp.o.provides.build: source/CMakeFiles/tests.dir/testlist.cpp.o

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/testlist.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: source/CMakeFiles/tests.dir/testlist.cpp.o
tests: source/CMakeFiles/tests.dir/build.make
tests: source/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../tests"
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/tests.dir/build: tests
.PHONY : source/CMakeFiles/tests.dir/build

source/CMakeFiles/tests.dir/requires: source/CMakeFiles/tests.dir/testlist.cpp.o.requires
.PHONY : source/CMakeFiles/tests.dir/requires

source/CMakeFiles/tests.dir/clean:
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/tests.dir/clean

source/CMakeFiles/tests.dir/depend:
	cd "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4" "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/source" "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build" "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source" "/home/vanya/Programmiersprachen/Exercise 4/programmiersprachen_aufgabenblatt_4/build/source/CMakeFiles/tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : source/CMakeFiles/tests.dir/depend

