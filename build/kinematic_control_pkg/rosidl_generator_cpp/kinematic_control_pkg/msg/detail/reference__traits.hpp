// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinematic_control_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__TRAITS_HPP_
#define KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinematic_control_pkg/msg/detail/reference__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace kinematic_control_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Reference & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Reference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Reference & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace kinematic_control_pkg

namespace rosidl_generator_traits
{

[[deprecated("use kinematic_control_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinematic_control_pkg::msg::Reference & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinematic_control_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinematic_control_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const kinematic_control_pkg::msg::Reference & msg)
{
  return kinematic_control_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kinematic_control_pkg::msg::Reference>()
{
  return "kinematic_control_pkg::msg::Reference";
}

template<>
inline const char * name<kinematic_control_pkg::msg::Reference>()
{
  return "kinematic_control_pkg/msg/Reference";
}

template<>
struct has_fixed_size<kinematic_control_pkg::msg::Reference>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<geometry_msgs::msg::Twist>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<kinematic_control_pkg::msg::Reference>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<geometry_msgs::msg::Twist>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<kinematic_control_pkg::msg::Reference>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__TRAITS_HPP_
