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
CMAKE_SOURCE_DIR = /home/shili/wlf_catkin_ws/src/nlink_parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shili/wlf_catkin_ws/build_isolated/nlink_parser

# Include any dependencies generated for this target.
include extern/serial/tests/CMakeFiles/serial-test.dir/depend.make

# Include the progress variables for this target.
include extern/serial/tests/CMakeFiles/serial-test.dir/progress.make

# Include the compile flags for this target's objects.
include extern/serial/tests/CMakeFiles/serial-test.dir/flags.make

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: extern/serial/tests/CMakeFiles/serial-test.dir/flags.make
extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o: /home/shili/wlf_catkin_ws/src/nlink_parser/extern/serial/tests/unix_serial_tests.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.o -c /home/shili/wlf_catkin_ws/src/nlink_parser/extern/serial/tests/unix_serial_tests.cc

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial-test.dir/unix_serial_tests.cc.i"
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shili/wlf_catkin_ws/src/nlink_parser/extern/serial/tests/unix_serial_tests.cc > CMakeFiles/serial-test.dir/unix_serial_tests.cc.i

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial-test.dir/unix_serial_tests.cc.s"
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shili/wlf_catkin_ws/src/nlink_parser/extern/serial/tests/unix_serial_tests.cc -o CMakeFiles/serial-test.dir/unix_serial_tests.cc.s

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.requires:

.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.requires

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.provides: extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.requires
	$(MAKE) -f extern/serial/tests/CMakeFiles/serial-test.dir/build.make extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.provides.build
.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.provides

extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.provides.build: extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o


# Object files for target serial-test
serial__test_OBJECTS = \
"CMakeFiles/serial-test.dir/unix_serial_tests.cc.o"

# External object files for target serial-test
serial__test_EXTERNAL_OBJECTS =

/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test: extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o
/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test: extern/serial/tests/CMakeFiles/serial-test.dir/build.make
/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test: gtest/googlemock/gtest/libgtest.so
/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test: /home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/libserial.so
/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test: extern/serial/tests/CMakeFiles/serial-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test"
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/serial/tests/CMakeFiles/serial-test.dir/build: /home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/serial/serial-test

.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/build

extern/serial/tests/CMakeFiles/serial-test.dir/requires: extern/serial/tests/CMakeFiles/serial-test.dir/unix_serial_tests.cc.o.requires

.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/requires

extern/serial/tests/CMakeFiles/serial-test.dir/clean:
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests && $(CMAKE_COMMAND) -P CMakeFiles/serial-test.dir/cmake_clean.cmake
.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/clean

extern/serial/tests/CMakeFiles/serial-test.dir/depend:
	cd /home/shili/wlf_catkin_ws/build_isolated/nlink_parser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shili/wlf_catkin_ws/src/nlink_parser /home/shili/wlf_catkin_ws/src/nlink_parser/extern/serial/tests /home/shili/wlf_catkin_ws/build_isolated/nlink_parser /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests /home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/tests/CMakeFiles/serial-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/serial/tests/CMakeFiles/serial-test.dir/depend

