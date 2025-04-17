cmake_minimum_required(VERSION 3.8)
project(laser_line_extraction)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)

find_package(rosidl_default_generators REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
  )

set(message_files
    "msg/LineSegment.msg"
	"msg/LineSegmentList.msg"
  )

rosidl_generate_interfaces(${PROJECT_NAME}
  ${message_files}
  DEPENDENCIES
    std_msgs
)

add_executable(line_extraction_node
src/line.cpp
src/line_extraction.cpp
src/line_extraction_node.cpp)

ament_target_dependencies(line_extraction_node
std_msgs
geometry_msgs
rclcpp
sensor_msgs
visualization_msgs
${EIGEN3_LIBRARIES}
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(line_extraction_node "${cpp_typesupport_target}")

install(TARGETS
line_extraction_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch 
DESTINATION share/${PROJECT_NAME})

ament_package()