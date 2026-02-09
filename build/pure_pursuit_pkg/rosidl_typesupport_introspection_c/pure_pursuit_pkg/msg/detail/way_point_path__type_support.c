// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pure_pursuit_pkg/msg/detail/way_point_path__rosidl_typesupport_introspection_c.h"
#include "pure_pursuit_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pure_pursuit_pkg/msg/detail/way_point_path__functions.h"
#include "pure_pursuit_pkg/msg/detail/way_point_path__struct.h"


// Include directives for member types
// Member `closed_path`
#include "std_msgs/msg/bool.h"
// Member `closed_path`
#include "std_msgs/msg/detail/bool__rosidl_typesupport_introspection_c.h"
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pure_pursuit_pkg__msg__WayPointPath__init(message_memory);
}

void pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_fini_function(void * message_memory)
{
  pure_pursuit_pkg__msg__WayPointPath__fini(message_memory);
}

size_t pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__size_function__WayPointPath__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_const_function__WayPointPath__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_function__WayPointPath__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__fetch_function__WayPointPath__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_const_function__WayPointPath__points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__assign_function__WayPointPath__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_function__WayPointPath__points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__resize_function__WayPointPath__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_member_array[2] = {
  {
    "closed_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pure_pursuit_pkg__msg__WayPointPath, closed_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pure_pursuit_pkg__msg__WayPointPath, points),  // bytes offset in struct
    NULL,  // default value
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__size_function__WayPointPath__points,  // size() function pointer
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_const_function__WayPointPath__points,  // get_const(index) function pointer
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__get_function__WayPointPath__points,  // get(index) function pointer
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__fetch_function__WayPointPath__points,  // fetch(index, &value) function pointer
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__assign_function__WayPointPath__points,  // assign(index, value) function pointer
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__resize_function__WayPointPath__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_members = {
  "pure_pursuit_pkg__msg",  // message namespace
  "WayPointPath",  // message name
  2,  // number of fields
  sizeof(pure_pursuit_pkg__msg__WayPointPath),
  pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_member_array,  // message members
  pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_init_function,  // function to initialize message memory (memory has to be allocated)
  pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_type_support_handle = {
  0,
  &pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pure_pursuit_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pure_pursuit_pkg, msg, WayPointPath)() {
  pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Bool)();
  pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_type_support_handle.typesupport_identifier) {
    pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pure_pursuit_pkg__msg__WayPointPath__rosidl_typesupport_introspection_c__WayPointPath_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
