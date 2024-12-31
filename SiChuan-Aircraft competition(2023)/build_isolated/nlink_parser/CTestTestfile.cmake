# CMake generated Testfile for 
# Source directory: /home/shili/wlf_catkin_ws/src/nlink_parser
# Build directory: /home/shili/wlf_catkin_ws/build_isolated/nlink_parser
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_nlink_parser_gtest_nlink_parser_test "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/test_results/nlink_parser/gtest-nlink_parser_test.xml" "--return-code" "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/nlink_parser/nlink_parser_test --gtest_output=xml:/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/test_results/nlink_parser/gtest-nlink_parser_test.xml")
subdirs("gtest")
subdirs("extern/serial")
