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
CMAKE_SOURCE_DIR = /home/cindy/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cindy/catkin_ws/build

# Include any dependencies generated for this target.
include serial/tests/CMakeFiles/serial-test.dir/depend.make

# Include the progress variables for this target.
include serial/tests/CMakeFiles/serial-test.dir/progress.make

# Include the compile flags for this target's objects.
include serial/tests/CMakeFiles/serial-test.dir/flags.make

serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: serial/tests/CMakeFiles/serial-test.dir/flags.make
serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: /home/cindy/catkin_ws/src/serial/tests/unix_serial_tests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cindy/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"
	cd /home/cindy/catkin_ws/build/serial/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.o -c /home/cindy/catkin_ws/src/serial/tests/unix_serial_tests.cc

serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial-test.dir/unix_serial_tests.cc.i"
	cd /home/cindy/catkin_ws/build/serial/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cindy/catkin_ws/src/serial/tests/unix_serial_tests.cc > CMakeFiles/serial-test.dir/unix_serial_tests.cc.i

serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial-test.dir/unix_serial_tests.cc.s"
	cd /home/cindy/catkin_ws/build/serial/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cindy/catkin_ws/src/serial/tests/unix_serial_tests.cc -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.s

# Object files for target serial-test
serial__test_OBJECTS = \
"CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"

# External object files for target serial-test
serial__test_EXTERNAL_OBJECTS =

/home/cindy/catkin_ws/devel/lib/serial/serial-test: serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o
/home/cindy/catkin_ws/devel/lib/serial/serial-test: serial/tests/CMakeFiles/serial-test.dir/build.make
/home/cindy/catkin_ws/devel/lib/serial/serial-test: gtest/lib/libgtest.so
/home/cindy/catkin_ws/devel/lib/serial/serial-test: /home/cindy/catkin_ws/devel/lib/libserial.so
/home/cindy/catkin_ws/devel/lib/serial/serial-test: serial/tests/CMakeFiles/serial-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cindy/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/cindy/catkin_ws/devel/lib/serial/serial-test"
	cd /home/cindy/catkin_ws/build/serial/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serial/tests/CMakeFiles/serial-test.dir/build: /home/cindy/catkin_ws/devel/lib/serial/serial-test

.PHONY : serial/tests/CMakeFiles/serial-test.dir/build

serial/tests/CMakeFiles/serial-test.dir/clean:
	cd /home/cindy/catkin_ws/build/serial/tests && $(CMAKE_COMMAND) -P CMakeFiles/serial-test.dir/cmake_clean.cmake
.PHONY : serial/tests/CMakeFiles/serial-test.dir/clean

serial/tests/CMakeFiles/serial-test.dir/depend:
	cd /home/cindy/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cindy/catkin_ws/src /home/cindy/catkin_ws/src/serial/tests /home/cindy/catkin_ws/build /home/cindy/catkin_ws/build/serial/tests /home/cindy/catkin_ws/build/serial/tests/CMakeFiles/serial-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serial/tests/CMakeFiles/serial-test.dir/depend

