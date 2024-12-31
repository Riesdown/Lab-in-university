# Install script for directory: /home/shili/wlf_catkin_ws/src/nlink_parser

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/shili/wlf_catkin_ws/install_isolated")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE PROGRAM FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE PROGRAM FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/setup.bash;/home/shili/wlf_catkin_ws/install_isolated/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE FILE FILES
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/setup.bash"
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/setup.sh;/home/shili/wlf_catkin_ws/install_isolated/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE FILE FILES
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/setup.sh"
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/setup.zsh;/home/shili/wlf_catkin_ws/install_isolated/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE FILE FILES
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/setup.zsh"
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/shili/wlf_catkin_ws/install_isolated/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/shili/wlf_catkin_ws/install_isolated" TYPE FILE FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nlink_parser/msg" TYPE FILE FILES
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackAnchorframe0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode1.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode2.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe1.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe2.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe3.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackTag.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackTagframe0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/TofsenseCascade.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/TofsenseFrame0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackAoaNode0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackAoaNodeframe0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode4Anchor.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode4Tag.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe4.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode5.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe5.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNode6.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/LinktrackNodeframe6.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/TofsenseMFrame0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/TofsenseMFrame0Pixel.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/IotFrame0.msg"
    "/home/shili/wlf_catkin_ws/src/nlink_parser/msg/IotFrame0Node.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nlink_parser/cmake" TYPE FILE FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/nlink_parser-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/include/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/share/roseus/ros/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/share/common-lisp/ros/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/share/gennodejs/ros/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/python2.7/dist-packages/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/shili/wlf_catkin_ws/devel_isolated/nlink_parser/lib/python2.7/dist-packages/nlink_parser")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/nlink_parser.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nlink_parser/cmake" TYPE FILE FILES "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/nlink_parser-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nlink_parser/cmake" TYPE FILE FILES
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/nlink_parserConfig.cmake"
    "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/catkin_generated/installspace/nlink_parserConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nlink_parser" TYPE FILE FILES "/home/shili/wlf_catkin_ws/src/nlink_parser/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/gtest/cmake_install.cmake")
  include("/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/extern/serial/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/shili/wlf_catkin_ws/build_isolated/nlink_parser/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
