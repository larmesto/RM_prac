// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_laser_scan_matcher:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__BUILDER_HPP_
#define ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_laser_scan_matcher/srv/detail/reset_odom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_laser_scan_matcher
{

namespace srv
{

namespace builder
{

class Init_ResetOdom_Request_reset
{
public:
  Init_ResetOdom_Request_reset()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_laser_scan_matcher::srv::ResetOdom_Request reset(::ros2_laser_scan_matcher::srv::ResetOdom_Request::_reset_type arg)
  {
    msg_.reset = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_laser_scan_matcher::srv::ResetOdom_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_laser_scan_matcher::srv::ResetOdom_Request>()
{
  return ros2_laser_scan_matcher::srv::builder::Init_ResetOdom_Request_reset();
}

}  // namespace ros2_laser_scan_matcher


namespace ros2_laser_scan_matcher
{

namespace srv
{

namespace builder
{

class Init_ResetOdom_Response_response
{
public:
  Init_ResetOdom_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_laser_scan_matcher::srv::ResetOdom_Response response(::ros2_laser_scan_matcher::srv::ResetOdom_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_laser_scan_matcher::srv::ResetOdom_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_laser_scan_matcher::srv::ResetOdom_Response>()
{
  return ros2_laser_scan_matcher::srv::builder::Init_ResetOdom_Response_response();
}

}  // namespace ros2_laser_scan_matcher

#endif  // ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__BUILDER_HPP_
