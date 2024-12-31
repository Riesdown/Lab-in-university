cmake_minimum_required(VERSION 3.0.2)
project(test)

add_compile_options(-std=c++17)

# 添加依赖项
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_generation
)

# 添加自定义消息文件
add_message_files(
  FILES
  piece.msg
  all_position.msg
  key_send.msg
  next_piece.msg
)

# 生成消息
generate_messages(
  DEPENDENCIES
  std_msgs
)

# 包含目录
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# 确保文件能执行
catkin_package(
  CATKIN_DEPENDS message_runtime roscpp std_msgs geometry_msgs
)

add_executable(sch src/SYS/Task_Sch.cpp)
target_link_libraries(sch ${catkin_LIBRARIES})
add_dependencies(sch ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(test1 src/TEST/test1.cpp)
target_link_libraries(test1 ${catkin_LIBRARIES})
add_dependencies(test1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(send src/WORK/Angle_Send_Position.cpp)
target_link_libraries(send ${catkin_LIBRARIES})
add_dependencies(send ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


add_executable(arm src/WORK/Arm_Contorl.cpp)
target_link_libraries(arm ${catkin_LIBRARIES})
add_dependencies(arm ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ai src/WORK/Algorithm.cpp)
target_link_libraries(ai ${catkin_LIBRARIES})
add_dependencies(ai ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


