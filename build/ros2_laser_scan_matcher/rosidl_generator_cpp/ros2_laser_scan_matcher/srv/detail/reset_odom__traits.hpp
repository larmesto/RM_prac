// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_laser_scan_matcher:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_
#define ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_laser_scan_matcher/srv/detail/reset_odom__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_laser_scan_matcher
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetOdom_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: reset
  {
    out << "reset: ";
    rosidl_generator_traits::value_to_yaml(msg.reset, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetOdom_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reset: ";
    rosidl_generator_traits::value_to_yaml(msg.reset, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetOdom_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace rosidl_generator_traits
{

[[deprecated("use ros2_laser_scan_matcher::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_laser_scan_matcher::srv::ResetOdom_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_laser_scan_matcher::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_laser_scan_matcher::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_laser_scan_matcher::srv::ResetOdom_Request & msg)
{
  return ros2_laser_scan_matcher::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_laser_scan_matcher::srv::ResetOdom_Request>()
{
  return "ros2_laser_scan_matcher::srv::ResetOdom_Request";
}

template<>
inline const char * name<ros2_laser_scan_matcher::srv::ResetOdom_Request>()
{
  return "ros2_laser_scan_matcher/srv/ResetOdom_Request";
}

template<>
struct has_fixed_size<ros2_laser_scan_matcher::srv::ResetOdom_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_laser_scan_matcher::srv::ResetOdom_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_laser_scan_matcher::srv::ResetOdom_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_laser_scan_matcher
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetOdom_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetOdom_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetOdom_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace rosidl_generator_traits
{

[[deprecated("use ros2_laser_scan_matcher::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_laser_scan_matcher::srv::ResetOdom_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_laser_scan_matcher::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_laser_scan_matcher::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_laser_scan_matcher::srv::ResetOdom_Response & msg)
{
  return ros2_laser_scan_matcher::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_laser_scan_matcher::srv::ResetOdom_Response>()
{
  return "ros2_laser_scan_matcher::srv::ResetOdom_Response";
}

template<>
inline const char * name<ros2_laser_scan_matcher::srv::ResetOdom_Response>()
{
  return "ros2_laser_scan_matcher/srv/ResetOdom_Response";
}

template<>
struct has_fixed_size<ros2_laser_scan_matcher::srv::ResetOdom_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_laser_scan_matcher::srv::ResetOdom_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_laser_scan_matcher::srv::ResetOdom_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_laser_scan_matcher::srv::ResetOdom>()
{
  return "ros2_laser_scan_matcher::srv::ResetOdom";
}

template<>
inline const char * name<ros2_laser_scan_matcher::srv::ResetOdom>()
{
  return "ros2_laser_scan_matcher/srv/ResetOdom";
}

template<>
struct has_fixed_size<ros2_laser_scan_matcher::srv::ResetOdom>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_laser_scan_matcher::srv::ResetOdom_Request>::value &&
    has_fixed_size<ros2_laser_scan_matcher::srv::ResetOdom_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_laser_scan_matcher::srv::ResetOdom>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_laser_scan_matcher::srv::ResetOdom_Request>::value &&
    has_bounded_size<ros2_laser_scan_matcher::srv::ResetOdom_Response>::value
  >
{
};

template<>
struct is_service<ros2_laser_scan_matcher::srv::ResetOdom>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_laser_scan_matcher::srv::ResetOdom_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_laser_scan_matcher::srv::ResetOdom_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__TRAITS_HPP_
