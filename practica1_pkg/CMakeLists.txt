cmake_minimum_required(VERSION 3.8)
project(practica1_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(tf2_geometry_msgs REQUIRED)

# Executables with dependencies
#-----------------------------------------

add_executable(publisher 
src/publisher_node.cpp)

ament_target_dependencies(publisher
rclcpp 
tf2_geometry_msgs)

#-----------------------------------------

add_executable(subscriber 
src/subscriber_node.cpp)

ament_target_dependencies(subscriber
rclcpp 
tf2_geometry_msgs)

#-----------------------------------------

# Install folder (executables inside)
install(TARGETS
publisher
subscriber
DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
