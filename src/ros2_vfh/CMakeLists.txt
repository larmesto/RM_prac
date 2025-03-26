cmake_minimum_required(VERSION 3.8)
project(ros2_vfh)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
#find_package(tf2 REQUIRED)
#find_package(tf2_geometry_msgs REQUIRED)
#find_package(tf2_ros REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


#find_package(tf2_eigen REQUIRED)

find_package(nav_msgs REQUIRED)

#find_package(rosidl_default_generators REQUIRED)

#rosidl_generate_interfaces(${PROJECT_NAME}
#  "msg/Reference.msg"
#  DEPENDENCIES
#    geometry_msgs
#    std_msgs
# )

include_directories(
  include
  )

add_executable(vfh_node
src/vfh_node.cpp
src/vfh_algorithm.cc)


ament_target_dependencies(
  vfh_node
  rclcpp
  std_msgs
  nav_msgs
  sensor_msgs
  #tf2_ros
  #tf2
  #tf2_geometry_msgs
)

install(TARGETS vfh_node DESTINATION lib/${PROJECT_NAME})

ament_package()