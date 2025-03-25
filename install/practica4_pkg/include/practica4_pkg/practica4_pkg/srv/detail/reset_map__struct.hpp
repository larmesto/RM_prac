// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_HPP_
#define PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__practica4_pkg__srv__ResetMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__practica4_pkg__srv__ResetMap_Request __declspec(deprecated)
#endif

namespace practica4_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetMap_Request_
{
  using Type = ResetMap_Request_<ContainerAllocator>;

  explicit ResetMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reset_req = false;
    }
  }

  explicit ResetMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reset_req = false;
    }
  }

  // field types and members
  using _reset_req_type =
    bool;
  _reset_req_type reset_req;

  // setters for named parameter idiom
  Type & set__reset_req(
    const bool & _arg)
  {
    this->reset_req = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__practica4_pkg__srv__ResetMap_Request
    std::shared_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__practica4_pkg__srv__ResetMap_Request
    std::shared_ptr<practica4_pkg::srv::ResetMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetMap_Request_ & other) const
  {
    if (this->reset_req != other.reset_req) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetMap_Request_

// alias to use template instance with default allocator
using ResetMap_Request =
  practica4_pkg::srv::ResetMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace practica4_pkg


#ifndef _WIN32
# define DEPRECATED__practica4_pkg__srv__ResetMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__practica4_pkg__srv__ResetMap_Response __declspec(deprecated)
#endif

namespace practica4_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetMap_Response_
{
  using Type = ResetMap_Response_<ContainerAllocator>;

  explicit ResetMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit ResetMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__practica4_pkg__srv__ResetMap_Response
    std::shared_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__practica4_pkg__srv__ResetMap_Response
    std::shared_ptr<practica4_pkg::srv::ResetMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetMap_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetMap_Response_

// alias to use template instance with default allocator
using ResetMap_Response =
  practica4_pkg::srv::ResetMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace practica4_pkg

namespace practica4_pkg
{

namespace srv
{

struct ResetMap
{
  using Request = practica4_pkg::srv::ResetMap_Request;
  using Response = practica4_pkg::srv::ResetMap_Response;
};

}  // namespace srv

}  // namespace practica4_pkg

#endif  // PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__STRUCT_HPP_
