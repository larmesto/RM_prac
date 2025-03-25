// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from practica5_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "practica5_pkg/msg/detail/reference__rosidl_typesupport_introspection_c.h"
#include "practica5_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "practica5_pkg/msg/detail/reference__functions.h"
#include "practica5_pkg/msg/detail/reference__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "geometry_msgs/msg/twist.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  practica5_pkg__msg__Reference__init(message_memory);
}

void practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_fini_function(void * message_memory)
{
  practica5_pkg__msg__Reference__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(practica5_pkg__msg__Reference, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(practica5_pkg__msg__Reference, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(practica5_pkg__msg__Reference, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_members = {
  "practica5_pkg__msg",  // message namespace
  "Reference",  // message name
  3,  // number of fields
  sizeof(practica5_pkg__msg__Reference),
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_member_array,  // message members
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_init_function,  // function to initialize message memory (memory has to be allocated)
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_type_support_handle = {
  0,
  &practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_practica5_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, practica5_pkg, msg, Reference)() {
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_type_support_handle.typesupport_identifier) {
    practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &practica5_pkg__msg__Reference__rosidl_typesupport_introspection_c__Reference_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
