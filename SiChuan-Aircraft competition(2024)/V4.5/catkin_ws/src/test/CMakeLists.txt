cmake_minimum_required(VERSION 3.0.2)
project(test)

add_compile_options(-std=c++17)

# 添加依赖项
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  mavros_msgs
  message_generation
  nlink_parser
  mavros
  sensor_msgs
  pcl_ros
)




# 添加自定义消息文件
add_message_files(
  FILES
  set_position.msg
  cloud_date.msg
  avoidant_date.msg
  fly_position.msg
  circle.msg
)

# add_service_files(
#   FILES
# )

# # 下面的行确保 Python 包可用
# catkin_python_setup()

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
  CATKIN_DEPENDS message_runtime
  CATKIN_DEPENDS roscpp mavros_msgs std_msgs geometry_msgs
)



# Work
add_executable(offboard src/WORK/INoffboard.cpp)
add_dependencies(offboard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(offboard ${catkin_LIBRARIES})

add_executable(state src/TEST/Look_State.cpp)
add_dependencies(state ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(state ${catkin_LIBRARIES})


add_executable(unlock src/WORK/Unlock.cpp)
target_link_libraries(unlock ${catkin_LIBRARIES})

add_executable(unlock2 src/WORK/Unlock2.cpp)
target_link_libraries(unlock2 ${catkin_LIBRARIES})

add_executable(fix src/WORK/Fixed_Path.cpp)
target_link_libraries(fix ${catkin_LIBRARIES})
add_dependencies(fix ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(fix2 src/WORK/Fixed_Path2.cpp)
target_link_libraries(fix2 ${catkin_LIBRARIES})
add_dependencies(fix2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


add_executable(vary src/WORK/Vary_Path.cpp)
target_link_libraries(vary ${catkin_LIBRARIES})
add_dependencies(vary ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})



add_executable(avoid1 src/APP/Avoid_V1.cpp)
target_link_libraries(avoid1 ${catkin_LIBRARIES})
add_dependencies(avoid1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


add_executable(origin src/SYS/Send_origin.cpp)
target_link_libraries(origin ${catkin_LIBRARIES})
add_dependencies(origin ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(send_cloud src/APP/Send_Cloud.cpp)
target_link_libraries(send_cloud ${catkin_LIBRARIES})
add_dependencies(send_cloud ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(avoid2 src/APP/Avoid_V2.cpp)
target_link_libraries(avoid2 ${catkin_LIBRARIES})
add_dependencies(avoid2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(avoid3 src/APP/Avoid_V3.cpp)
target_link_libraries(avoid3 ${catkin_LIBRARIES})
add_dependencies(avoid3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(test1 src/TEST/test1.cpp)
add_dependencies(test1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(test1 ${catkin_LIBRARIES})