// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from practica5_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_
#define PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_

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

/// Struct defined in msg/Reference in the package practica5_pkg.
typedef struct practica5_pkg__msg__Reference
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist velocity;
} practica5_pkg__msg__Reference;

// Struct for a sequence of practica5_pkg__msg__Reference.
typedef struct practica5_pkg__msg__Reference__Sequence
{
  practica5_pkg__msg__Reference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} practica5_pkg__msg__Reference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_H_
