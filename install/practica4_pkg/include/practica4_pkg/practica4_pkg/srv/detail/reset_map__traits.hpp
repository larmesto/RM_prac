// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__TRAITS_HPP_
#define PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "practica4_pkg/srv/detail/reset_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace practica4_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetMap_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: reset_req
  {
    out << "reset_req: ";
    rosidl_generator_traits::value_to_yaml(msg.reset_req, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reset_req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reset_req: ";
    rosidl_generator_traits::value_to_yaml(msg.reset_req, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetMap_Request & msg, bool use_flow_style = false)
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

}  // namespace practica4_pkg

namespace rosidl_generator_traits
{

[[deprecated("use practica4_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const practica4_pkg::srv::ResetMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  practica4_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use practica4_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const practica4_pkg::srv::ResetMap_Request & msg)
{
  return practica4_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<practica4_pkg::srv::ResetMap_Request>()
{
  return "practica4_pkg::srv::ResetMap_Request";
}

template<>
inline const char * name<practica4_pkg::srv::ResetMap_Request>()
{
  return "practica4_pkg/srv/ResetMap_Request";
}

template<>
struct has_fixed_size<practica4_pkg::srv::ResetMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<practica4_pkg::srv::ResetMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<practica4_pkg::srv::ResetMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace practica4_pkg
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetMap_Response & msg,
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
  const ResetMap_Response & msg,
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

inline std::string to_yaml(const ResetMap_Response & msg, bool use_flow_style = false)
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

}  // namespace practica4_pkg

namespace rosidl_generator_traits
{

[[deprecated("use practica4_pkg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const practica4_pkg::srv::ResetMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  practica4_pkg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use practica4_pkg::srv::to_yaml() instead")]]
inline std::string to_yaml(const practica4_pkg::srv::ResetMap_Response & msg)
{
  return practica4_pkg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<practica4_pkg::srv::ResetMap_Response>()
{
  return "practica4_pkg::srv::ResetMap_Response";
}

template<>
inline const char * name<practica4_pkg::srv::ResetMap_Response>()
{
  return "practica4_pkg/srv/ResetMap_Response";
}

template<>
struct has_fixed_size<practica4_pkg::srv::ResetMap_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<practica4_pkg::srv::ResetMap_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<practica4_pkg::srv::ResetMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<practica4_pkg::srv::ResetMap>()
{
  return "practica4_pkg::srv::ResetMap";
}

template<>
inline const char * name<practica4_pkg::srv::ResetMap>()
{
  return "practica4_pkg/srv/ResetMap";
}

template<>
struct has_fixed_size<practica4_pkg::srv::ResetMap>
  : std::integral_constant<
    bool,
    has_fixed_size<practica4_pkg::srv::ResetMap_Request>::value &&
    has_fixed_size<practica4_pkg::srv::ResetMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<practica4_pkg::srv::ResetMap>
  : std::integral_constant<
    bool,
    has_bounded_size<practica4_pkg::srv::ResetMap_Request>::value &&
    has_bounded_size<practica4_pkg::srv::ResetMap_Response>::value
  >
{
};

template<>
struct is_service<practica4_pkg::srv::ResetMap>
  : std::true_type
{
};

template<>
struct is_service_request<practica4_pkg::srv::ResetMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<practica4_pkg::srv::ResetMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__TRAITS_HPP_
