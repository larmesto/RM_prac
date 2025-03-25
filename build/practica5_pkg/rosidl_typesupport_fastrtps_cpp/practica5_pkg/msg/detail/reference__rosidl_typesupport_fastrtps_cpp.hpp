// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from practica5_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA5_PKG__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PRACTICA5_PKG__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "practica5_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "practica5_pkg/msg/detail/reference__struct.hpp"

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

namespace practica5_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_practica5_pkg
cdr_serialize(
  const practica5_pkg::msg::Reference & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_practica5_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  practica5_pkg::msg::Reference & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_practica5_pkg
get_serialized_size(
  const practica5_pkg::msg::Reference & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_practica5_pkg
max_serialized_size_Reference(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace practica5_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_practica5_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, practica5_pkg, msg, Reference)();

#ifdef __cplusplus
}
#endif

#endif  // PRACTICA5_PKG__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
