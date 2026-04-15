// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#ifndef PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pure_pursuit_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pure_pursuit_pkg/msg/detail/way_point_path__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace pure_pursuit_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pure_pursuit_pkg
cdr_serialize(
  const pure_pursuit_pkg::msg::WayPointPath & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pure_pursuit_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pure_pursuit_pkg::msg::WayPointPath & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pure_pursuit_pkg
get_serialized_size(
  const pure_pursuit_pkg::msg::WayPointPath & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pure_pursuit_pkg
max_serialized_size_WayPointPath(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pure_pursuit_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pure_pursuit_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pure_pursuit_pkg, msg, WayPointPath)();

#ifdef __cplusplus
}
#endif

#endif  // PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
