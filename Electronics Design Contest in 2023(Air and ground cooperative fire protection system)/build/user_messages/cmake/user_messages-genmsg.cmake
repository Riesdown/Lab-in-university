# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "user_messages: 3 messages, 0 services")

set(MSG_I_FLAGS "-Iuser_messages:/home/cindy/catkin_ws/src/user_messages/msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/noetic/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(user_messages_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_custom_target(_user_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "user_messages" "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" ""
)

get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_custom_target(_user_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "user_messages" "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" ""
)

get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_custom_target(_user_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "user_messages" "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages
)
_generate_msg_cpp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages
)
_generate_msg_cpp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages
)

### Generating Services

### Generating Module File
_generate_module_cpp(user_messages
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(user_messages_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(user_messages_generate_messages user_messages_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_cpp _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_cpp _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_cpp _user_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(user_messages_gencpp)
add_dependencies(user_messages_gencpp user_messages_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS user_messages_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages
)
_generate_msg_eus(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages
)
_generate_msg_eus(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages
)

### Generating Services

### Generating Module File
_generate_module_eus(user_messages
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(user_messages_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(user_messages_generate_messages user_messages_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_eus _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_eus _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_eus _user_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(user_messages_geneus)
add_dependencies(user_messages_geneus user_messages_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS user_messages_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages
)
_generate_msg_lisp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages
)
_generate_msg_lisp(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages
)

### Generating Services

### Generating Module File
_generate_module_lisp(user_messages
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(user_messages_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(user_messages_generate_messages user_messages_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_lisp _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_lisp _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_lisp _user_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(user_messages_genlisp)
add_dependencies(user_messages_genlisp user_messages_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS user_messages_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages
)
_generate_msg_nodejs(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages
)
_generate_msg_nodejs(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages
)

### Generating Services

### Generating Module File
_generate_module_nodejs(user_messages
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(user_messages_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(user_messages_generate_messages user_messages_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_nodejs _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_nodejs _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_nodejs _user_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(user_messages_gennodejs)
add_dependencies(user_messages_gennodejs user_messages_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS user_messages_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages
)
_generate_msg_py(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages
)
_generate_msg_py(user_messages
  "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages
)

### Generating Services

### Generating Module File
_generate_module_py(user_messages
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(user_messages_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(user_messages_generate_messages user_messages_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/navigation_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_py _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/position_ctrl.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_py _user_messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/cindy/catkin_ws/src/user_messages/msg/serialport_decode.msg" NAME_WE)
add_dependencies(user_messages_generate_messages_py _user_messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(user_messages_genpy)
add_dependencies(user_messages_genpy user_messages_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS user_messages_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/user_messages
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(user_messages_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(user_messages_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(user_messages_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(user_messages_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/user_messages
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(user_messages_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(user_messages_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(user_messages_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(user_messages_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/user_messages
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(user_messages_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(user_messages_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(user_messages_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(user_messages_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/user_messages
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(user_messages_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(user_messages_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(user_messages_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(user_messages_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/user_messages
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(user_messages_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(user_messages_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(user_messages_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(user_messages_generate_messages_py std_msgs_generate_messages_py)
endif()
