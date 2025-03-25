// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_H_
#define PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetMap in the package practica4_pkg.
typedef struct practica4_pkg__srv__ResetMap_Request
{
  bool reset_req;
} practica4_pkg__srv__ResetMap_Request;

// Struct for a sequence of practica4_pkg__srv__ResetMap_Request.
typedef struct practica4_pkg__srv__ResetMap_Request__Sequence
{
  practica4_pkg__srv__ResetMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} practica4_pkg__srv__ResetMap_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResetMap in the package practica4_pkg.
typedef struct practica4_pkg__srv__ResetMap_Response
{
  rosidl_runtime_c__String response;
} practica4_pkg__srv__ResetMap_Response;

// Struct for a sequence of practica4_pkg__srv__ResetMap_Response.
typedef struct practica4_pkg__srv__ResetMap_Response__Sequence
{
  practica4_pkg__srv__ResetMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} practica4_pkg__srv__ResetMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_H_
