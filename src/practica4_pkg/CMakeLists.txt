cmake_minimum_required(VERSION 3.8)
project(practica4_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

find_package(tf2_eigen REQUIRED)

find_package(nav_msgs REQUIRED)

find_package(laser_geometry)
find_package(sensor_msgs REQUIRED)
find_package(tf2_sensor_msgs REQUIRED)

find_package(PCL REQUIRED QUIET)
find_package(pcl_conversions REQUIRED)

find_package(visualization_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

set(service_files
    "srv/ResetMap.srv"
  )

rosidl_generate_interfaces(${PROJECT_NAME}
  ${service_files}
  DEPENDENCIES builtin_interfaces
)
	
add_executable(map_pointcloud_node
src/map_pointcloud_node.cpp)

ament_target_dependencies(map_pointcloud_node
std_msgs
geometry_msgs
rclcpp
tf2
tf2_geometry_msgs
sensor_msgs
laser_geometry
tf2_sensor_msgs
pcl_conversions
PCL
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(map_pointcloud_node "${cpp_typesupport_target}")

install(TARGETS
map_pointcloud_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch rviz 
DESTINATION share/${PROJECT_NAME})

ament_package()
