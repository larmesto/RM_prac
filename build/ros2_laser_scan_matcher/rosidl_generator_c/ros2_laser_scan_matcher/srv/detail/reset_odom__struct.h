// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_laser_scan_matcher:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_H_
#define ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetOdom in the package ros2_laser_scan_matcher.
typedef struct ros2_laser_scan_matcher__srv__ResetOdom_Request
{
  bool reset;
} ros2_laser_scan_matcher__srv__ResetOdom_Request;

// Struct for a sequence of ros2_laser_scan_matcher__srv__ResetOdom_Request.
typedef struct ros2_laser_scan_matcher__srv__ResetOdom_Request__Sequence
{
  ros2_laser_scan_matcher__srv__ResetOdom_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_laser_scan_matcher__srv__ResetOdom_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResetOdom in the package ros2_laser_scan_matcher.
typedef struct ros2_laser_scan_matcher__srv__ResetOdom_Response
{
  rosidl_runtime_c__String response;
} ros2_laser_scan_matcher__srv__ResetOdom_Response;

// Struct for a sequence of ros2_laser_scan_matcher__srv__ResetOdom_Response.
typedef struct ros2_laser_scan_matcher__srv__ResetOdom_Response__Sequence
{
  ros2_laser_scan_matcher__srv__ResetOdom_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_laser_scan_matcher__srv__ResetOdom_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_H_
