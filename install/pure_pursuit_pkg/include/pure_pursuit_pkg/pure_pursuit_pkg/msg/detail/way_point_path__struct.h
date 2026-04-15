// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#ifndef PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_H_
#define PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'closed_path'
#include "std_msgs/msg/detail/bool__struct.h"
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/WayPointPath in the package pure_pursuit_pkg.
typedef struct pure_pursuit_pkg__msg__WayPointPath
{
  std_msgs__msg__Bool closed_path;
  geometry_msgs__msg__Point__Sequence points;
} pure_pursuit_pkg__msg__WayPointPath;

// Struct for a sequence of pure_pursuit_pkg__msg__WayPointPath.
typedef struct pure_pursuit_pkg__msg__WayPointPath__Sequence
{
  pure_pursuit_pkg__msg__WayPointPath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pure_pursuit_pkg__msg__WayPointPath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_H_
