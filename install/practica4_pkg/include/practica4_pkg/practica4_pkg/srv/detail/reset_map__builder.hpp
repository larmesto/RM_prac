// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__BUILDER_HPP_
#define PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "practica4_pkg/srv/detail/reset_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace practica4_pkg
{

namespace srv
{

namespace builder
{

class Init_ResetMap_Request_reset_req
{
public:
  Init_ResetMap_Request_reset_req()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::practica4_pkg::srv::ResetMap_Request reset_req(::practica4_pkg::srv::ResetMap_Request::_reset_req_type arg)
  {
    msg_.reset_req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::practica4_pkg::srv::ResetMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::practica4_pkg::srv::ResetMap_Request>()
{
  return practica4_pkg::srv::builder::Init_ResetMap_Request_reset_req();
}

}  // namespace practica4_pkg


namespace practica4_pkg
{

namespace srv
{

namespace builder
{

class Init_ResetMap_Response_response
{
public:
  Init_ResetMap_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::practica4_pkg::srv::ResetMap_Response response(::practica4_pkg::srv::ResetMap_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::practica4_pkg::srv::ResetMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::practica4_pkg::srv::ResetMap_Response>()
{
  return practica4_pkg::srv::builder::Init_ResetMap_Response_response();
}

}  // namespace practica4_pkg

#endif  // PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__BUILDER_HPP_
