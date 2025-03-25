// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_laser_scan_matcher:srv/ResetOdom.idl
// generated code does not contain a copyright notice
#include "ros2_laser_scan_matcher/srv/detail/reset_odom__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_laser_scan_matcher/srv/detail/reset_odom__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_laser_scan_matcher
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
cdr_serialize(
  const ros2_laser_scan_matcher::srv::ResetOdom_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: reset
  cdr << (ros_message.reset ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_laser_scan_matcher::srv::ResetOdom_Request & ros_message)
{
  // Member: reset
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.reset = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
get_serialized_size(
  const ros2_laser_scan_matcher::srv::ResetOdom_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: reset
  {
    size_t item_size = sizeof(ros_message.reset);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
max_serialized_size_ResetOdom_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: reset
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros2_laser_scan_matcher::srv::ResetOdom_Request;
    is_plain =
      (
      offsetof(DataType, reset) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ResetOdom_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_laser_scan_matcher::srv::ResetOdom_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ResetOdom_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_laser_scan_matcher::srv::ResetOdom_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ResetOdom_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_laser_scan_matcher::srv::ResetOdom_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ResetOdom_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ResetOdom_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ResetOdom_Request__callbacks = {
  "ros2_laser_scan_matcher::srv",
  "ResetOdom_Request",
  _ResetOdom_Request__cdr_serialize,
  _ResetOdom_Request__cdr_deserialize,
  _ResetOdom_Request__get_serialized_size,
  _ResetOdom_Request__max_serialized_size
};

static rosidl_message_type_support_t _ResetOdom_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ResetOdom_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_laser_scan_matcher
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_laser_scan_matcher::srv::ResetOdom_Request>()
{
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_laser_scan_matcher, srv, ResetOdom_Request)() {
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_laser_scan_matcher
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
cdr_serialize(
  const ros2_laser_scan_matcher::srv::ResetOdom_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: response
  cdr << ros_message.response;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_laser_scan_matcher::srv::ResetOdom_Response & ros_message)
{
  // Member: response
  cdr >> ros_message.response;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
get_serialized_size(
  const ros2_laser_scan_matcher::srv::ResetOdom_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: response
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.response.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_laser_scan_matcher
max_serialized_size_ResetOdom_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: response
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros2_laser_scan_matcher::srv::ResetOdom_Response;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ResetOdom_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_laser_scan_matcher::srv::ResetOdom_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ResetOdom_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_laser_scan_matcher::srv::ResetOdom_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ResetOdom_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_laser_scan_matcher::srv::ResetOdom_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ResetOdom_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ResetOdom_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ResetOdom_Response__callbacks = {
  "ros2_laser_scan_matcher::srv",
  "ResetOdom_Response",
  _ResetOdom_Response__cdr_serialize,
  _ResetOdom_Response__cdr_deserialize,
  _ResetOdom_Response__get_serialized_size,
  _ResetOdom_Response__max_serialized_size
};

static rosidl_message_type_support_t _ResetOdom_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ResetOdom_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_laser_scan_matcher
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_laser_scan_matcher::srv::ResetOdom_Response>()
{
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_laser_scan_matcher, srv, ResetOdom_Response)() {
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace ros2_laser_scan_matcher
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ResetOdom__callbacks = {
  "ros2_laser_scan_matcher::srv",
  "ResetOdom",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_laser_scan_matcher, srv, ResetOdom_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_laser_scan_matcher, srv, ResetOdom_Response)(),
};

static rosidl_service_type_support_t _ResetOdom__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ResetOdom__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_laser_scan_matcher
const rosidl_service_type_support_t *
get_service_type_support_handle<ros2_laser_scan_matcher::srv::ResetOdom>()
{
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_laser_scan_matcher, srv, ResetOdom)() {
  return &ros2_laser_scan_matcher::srv::typesupport_fastrtps_cpp::_ResetOdom__handle;
}

#ifdef __cplusplus
}
#endif
