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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dji/git/taocky/cmake_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dji/git/taocky/cmake_test/build

# Include any dependencies generated for this target.
include double_pointer/bin/CMakeFiles/double_pointer.dir/depend.make

# Include the progress variables for this target.
include double_pointer/bin/CMakeFiles/double_pointer.dir/progress.make

# Include the compile flags for this target's objects.
include double_pointer/bin/CMakeFiles/double_pointer.dir/flags.make

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o: double_pointer/bin/CMakeFiles/double_pointer.dir/flags.make
double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o: ../double_pointer/src/double_pointer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dji/git/taocky/cmake_test/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o"
	cd /home/dji/git/taocky/cmake_test/build/double_pointer/bin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/double_pointer.dir/double_pointer.c.o   -c /home/dji/git/taocky/cmake_test/double_pointer/src/double_pointer.c

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/double_pointer.dir/double_pointer.c.i"
	cd /home/dji/git/taocky/cmake_test/build/double_pointer/bin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/dji/git/taocky/cmake_test/double_pointer/src/double_pointer.c > CMakeFiles/double_pointer.dir/double_pointer.c.i

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/double_pointer.dir/double_pointer.c.s"
	cd /home/dji/git/taocky/cmake_test/build/double_pointer/bin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/dji/git/taocky/cmake_test/double_pointer/src/double_pointer.c -o CMakeFiles/double_pointer.dir/double_pointer.c.s

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.requires:
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.requires

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.provides: double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.requires
	$(MAKE) -f double_pointer/bin/CMakeFiles/double_pointer.dir/build.make double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.provides.build
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.provides

double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.provides.build: double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o

# Object files for target double_pointer
double_pointer_OBJECTS = \
"CMakeFiles/double_pointer.dir/double_pointer.c.o"

# External object files for target double_pointer
double_pointer_EXTERNAL_OBJECTS =

double_pointer/bin/double_pointer: double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o
double_pointer/bin/double_pointer: double_pointer/bin/CMakeFiles/double_pointer.dir/build.make
double_pointer/bin/double_pointer: double_pointer/bin/CMakeFiles/double_pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable double_pointer"
	cd /home/dji/git/taocky/cmake_test/build/double_pointer/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/double_pointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
double_pointer/bin/CMakeFiles/double_pointer.dir/build: double_pointer/bin/double_pointer
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/build

double_pointer/bin/CMakeFiles/double_pointer.dir/requires: double_pointer/bin/CMakeFiles/double_pointer.dir/double_pointer.c.o.requires
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/requires

double_pointer/bin/CMakeFiles/double_pointer.dir/clean:
	cd /home/dji/git/taocky/cmake_test/build/double_pointer/bin && $(CMAKE_COMMAND) -P CMakeFiles/double_pointer.dir/cmake_clean.cmake
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/clean

double_pointer/bin/CMakeFiles/double_pointer.dir/depend:
	cd /home/dji/git/taocky/cmake_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dji/git/taocky/cmake_test /home/dji/git/taocky/cmake_test/double_pointer/src /home/dji/git/taocky/cmake_test/build /home/dji/git/taocky/cmake_test/build/double_pointer/bin /home/dji/git/taocky/cmake_test/build/double_pointer/bin/CMakeFiles/double_pointer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : double_pointer/bin/CMakeFiles/double_pointer.dir/depend

