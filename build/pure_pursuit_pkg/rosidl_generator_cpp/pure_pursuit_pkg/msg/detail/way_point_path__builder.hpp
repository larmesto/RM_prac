// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#ifndef PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__BUILDER_HPP_
#define PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pure_pursuit_pkg/msg/detail/way_point_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pure_pursuit_pkg
{

namespace msg
{

namespace builder
{

class Init_WayPointPath_points
{
public:
  explicit Init_WayPointPath_points(::pure_pursuit_pkg::msg::WayPointPath & msg)
  : msg_(msg)
  {}
  ::pure_pursuit_pkg::msg::WayPointPath points(::pure_pursuit_pkg::msg::WayPointPath::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pure_pursuit_pkg::msg::WayPointPath msg_;
};

class Init_WayPointPath_closed_path
{
public:
  Init_WayPointPath_closed_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WayPointPath_points closed_path(::pure_pursuit_pkg::msg::WayPointPath::_closed_path_type arg)
  {
    msg_.closed_path = std::move(arg);
    return Init_WayPointPath_points(msg_);
  }

private:
  ::pure_pursuit_pkg::msg::WayPointPath msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pure_pursuit_pkg::msg::WayPointPath>()
{
  return pure_pursuit_pkg::msg::builder::Init_WayPointPath_closed_path();
}

}  // namespace pure_pursuit_pkg

#endif  // PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__BUILDER_HPP_
