// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from practica5_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA5_PKG__MSG__DETAIL__REFERENCE__BUILDER_HPP_
#define PRACTICA5_PKG__MSG__DETAIL__REFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "practica5_pkg/msg/detail/reference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace practica5_pkg
{

namespace msg
{

namespace builder
{

class Init_Reference_velocity
{
public:
  explicit Init_Reference_velocity(::practica5_pkg::msg::Reference & msg)
  : msg_(msg)
  {}
  ::practica5_pkg::msg::Reference velocity(::practica5_pkg::msg::Reference::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::practica5_pkg::msg::Reference msg_;
};

class Init_Reference_pose
{
public:
  explicit Init_Reference_pose(::practica5_pkg::msg::Reference & msg)
  : msg_(msg)
  {}
  Init_Reference_velocity pose(::practica5_pkg::msg::Reference::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Reference_velocity(msg_);
  }

private:
  ::practica5_pkg::msg::Reference msg_;
};

class Init_Reference_header
{
public:
  Init_Reference_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Reference_pose header(::practica5_pkg::msg::Reference::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Reference_pose(msg_);
  }

private:
  ::practica5_pkg::msg::Reference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::practica5_pkg::msg::Reference>()
{
  return practica5_pkg::msg::builder::Init_Reference_header();
}

}  // namespace practica5_pkg

#endif  // PRACTICA5_PKG__MSG__DETAIL__REFERENCE__BUILDER_HPP_
