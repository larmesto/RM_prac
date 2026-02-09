// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinematic_control_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_
#define KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/Reference in the package kinematic_control_pkg.
typedef struct kinematic_control_pkg__msg__Reference
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist velocity;
} kinematic_control_pkg__msg__Reference;

// Struct for a sequence of kinematic_control_pkg__msg__Reference.
typedef struct kinematic_control_pkg__msg__Reference__Sequence
{
  kinematic_control_pkg__msg__Reference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinematic_control_pkg__msg__Reference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_
