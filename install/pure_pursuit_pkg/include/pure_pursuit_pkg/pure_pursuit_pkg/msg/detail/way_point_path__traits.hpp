// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#ifndef PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__TRAITS_HPP_
#define PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pure_pursuit_pkg/msg/detail/way_point_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'closed_path'
#include "std_msgs/msg/detail/bool__traits.hpp"
// Member 'points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace pure_pursuit_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const WayPointPath & msg,
  std::ostream & out)
{
  out << "{";
  // member: closed_path
  {
    out << "closed_path: ";
    to_flow_style_yaml(msg.closed_path, out);
    out << ", ";
  }

  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WayPointPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: closed_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "closed_path:\n";
    to_block_style_yaml(msg.closed_path, out, indentation + 2);
  }

  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WayPointPath & msg, bool use_flow_style = false)
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

}  // namespace pure_pursuit_pkg

namespace rosidl_generator_traits
{

[[deprecated("use pure_pursuit_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pure_pursuit_pkg::msg::WayPointPath & msg,
  std::ostream & out, size_t indentation = 0)
{
  pure_pursuit_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pure_pursuit_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const pure_pursuit_pkg::msg::WayPointPath & msg)
{
  return pure_pursuit_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pure_pursuit_pkg::msg::WayPointPath>()
{
  return "pure_pursuit_pkg::msg::WayPointPath";
}

template<>
inline const char * name<pure_pursuit_pkg::msg::WayPointPath>()
{
  return "pure_pursuit_pkg/msg/WayPointPath";
}

template<>
struct has_fixed_size<pure_pursuit_pkg::msg::WayPointPath>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pure_pursuit_pkg::msg::WayPointPath>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pure_pursuit_pkg::msg::WayPointPath>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__TRAITS_HPP_
