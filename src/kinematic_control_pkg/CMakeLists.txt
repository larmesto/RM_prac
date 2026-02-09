cmake_minimum_required(VERSION 3.8)
project(kinematic_control_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)


#find_package(tf2_eigen REQUIRED)

find_package(nav_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Reference.msg"
  DEPENDENCIES
    geometry_msgs
    std_msgs
 )

add_executable(controller_odom
src/controller_odom.cpp)

add_executable(infinite_reference_node
src/infinite_reference_node.cpp)

ament_target_dependencies(
  controller_odom
  rclcpp
  std_msgs
  nav_msgs
  tf2_ros
  tf2
  tf2_geometry_msgs
  visualization_msgs
)

ament_target_dependencies(
  infinite_reference_node
  rclcpp
  std_msgs
  geometry_msgs
  visualization_msgs
  tf2_geometry_msgs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(controller_odom "${cpp_typesupport_target}")
target_link_libraries(infinite_reference_node "${cpp_typesupport_target}")


install(TARGETS
controller_odom
infinite_reference_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY msg launch rviz
DESTINATION share/${PROJECT_NAME})

ament_package()
