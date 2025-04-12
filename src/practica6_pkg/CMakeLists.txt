cmake_minimum_required(VERSION 3.8)
project(practica6_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

find_package(visualization_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

find_package(yaml-cpp REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/WayPointPath.msg"
  DEPENDENCIES
    geometry_msgs
    std_msgs
 )
 
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

include_directories(
  include
  ${CMAKE_BINARY_DIR}/rosidl_generator_cpp
)

add_library(
  waypoint_tools_lib
  "src/waypoint_tools/WayPointPathTools.cpp"
)

target_include_directories(waypoint_tools_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_BINARY_DIR}/rosidl_generator_cpp
)

ament_target_dependencies(
  waypoint_tools_lib
  rclcpp
  std_msgs
  geometry_msgs
  visualization_msgs
  rosidl_default_runtime
)

add_dependencies(waypoint_tools_lib ${cpp_typesupport_target})

add_executable(pure_pursuit_odom
src/pure_pursuit_odom.cpp)

ament_target_dependencies(
  pure_pursuit_odom
  rclcpp
  std_msgs
  nav_msgs
  tf2_ros
  tf2
  tf2_geometry_msgs
  visualization_msgs
)


add_executable(waypoints_node
src/waypoints_node.cpp)

ament_target_dependencies(
  waypoints_node
  rclcpp
  std_msgs
  geometry_msgs
  visualization_msgs
)

add_dependencies(pure_pursuit_odom ${cpp_typesupport_target})
add_dependencies(waypoints_node ${cpp_typesupport_target})

target_link_libraries(pure_pursuit_odom waypoint_tools_lib "${cpp_typesupport_target}")
target_link_libraries(waypoints_node yaml-cpp "${cpp_typesupport_target}")

install(TARGETS
pure_pursuit_odom
waypoints_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY msg config launch
DESTINATION share/${PROJECT_NAME})

install(
  TARGETS waypoint_tools_lib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()
