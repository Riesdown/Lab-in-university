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
include auto_flight/CMakeFiles/auto_flight_demo.dir/depend.make

# Include the progress variables for this target.
include auto_flight/CMakeFiles/auto_flight_demo.dir/progress.make

# Include the compile flags for this target's objects.
include auto_flight/CMakeFiles/auto_flight_demo.dir/flags.make

auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o: auto_flight/CMakeFiles/auto_flight_demo.dir/flags.make
auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o: /home/cindy/catkin_ws/src/auto_flight/src/auto_flight_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cindy/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o"
	cd /home/cindy/catkin_ws/build/auto_flight && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o -c /home/cindy/catkin_ws/src/auto_flight/src/auto_flight_demo.cpp

auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.i"
	cd /home/cindy/catkin_ws/build/auto_flight && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cindy/catkin_ws/src/auto_flight/src/auto_flight_demo.cpp > CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.i

auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.s"
	cd /home/cindy/catkin_ws/build/auto_flight && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cindy/catkin_ws/src/auto_flight/src/auto_flight_demo.cpp -o CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.s

# Object files for target auto_flight_demo
auto_flight_demo_OBJECTS = \
"CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o"

# External object files for target auto_flight_demo
auto_flight_demo_EXTERNAL_OBJECTS =

/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: auto_flight/CMakeFiles/auto_flight_demo.dir/src/auto_flight_demo.cpp.o
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: auto_flight/CMakeFiles/auto_flight_demo.dir/build.make
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/libroscpp.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_chrono.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/librosconsole.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/liblog4cxx.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_regex.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/librostime.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_date_time.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /opt/ros/noetic/lib/libcpp_common.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_system.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libboost_thread.so.1.71.0
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /home/cindy/catkin_ws/devel/lib/libserial.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/librt.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo: auto_flight/CMakeFiles/auto_flight_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cindy/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo"
	cd /home/cindy/catkin_ws/build/auto_flight && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/auto_flight_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
auto_flight/CMakeFiles/auto_flight_demo.dir/build: /home/cindy/catkin_ws/devel/lib/auto_flight/auto_flight_demo

.PHONY : auto_flight/CMakeFiles/auto_flight_demo.dir/build

auto_flight/CMakeFiles/auto_flight_demo.dir/clean:
	cd /home/cindy/catkin_ws/build/auto_flight && $(CMAKE_COMMAND) -P CMakeFiles/auto_flight_demo.dir/cmake_clean.cmake
.PHONY : auto_flight/CMakeFiles/auto_flight_demo.dir/clean

auto_flight/CMakeFiles/auto_flight_demo.dir/depend:
	cd /home/cindy/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cindy/catkin_ws/src /home/cindy/catkin_ws/src/auto_flight /home/cindy/catkin_ws/build /home/cindy/catkin_ws/build/auto_flight /home/cindy/catkin_ws/build/auto_flight/CMakeFiles/auto_flight_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : auto_flight/CMakeFiles/auto_flight_demo.dir/depend

