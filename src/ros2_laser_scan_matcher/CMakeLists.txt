cmake_minimum_required(VERSION 3.5)

project(ros2_laser_scan_matcher)

find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rcutils REQUIRED)
find_package(PkgConfig)
find_package(csm REQUIRED)
find_package(Eigen3 REQUIRED)

find_package(rosidl_default_generators REQUIRED)

find_package(Boost COMPONENTS thread REQUIRED)

set(service_files
    "srv/ResetOdom.srv"
  )

rosidl_generate_interfaces(${PROJECT_NAME}
  ${service_files}
  DEPENDENCIES builtin_interfaces
)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIRS}
  )


add_executable(laser_scan_matcher src/laser_scan_matcher.cpp)

target_include_directories(laser_scan_matcher
  PRIVATE
  "include"
)

ament_target_dependencies(laser_scan_matcher
  rclcpp
  sensor_msgs
  rcutils
  Eigen3
  tf2_ros
  tf2
  tf2_geometry_msgs
  csm
  Boost
  nav_msgs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(laser_scan_matcher "${cpp_typesupport_target}")

install(TARGETS laser_scan_matcher DESTINATION lib/${PROJECT_NAME})


ament_package()