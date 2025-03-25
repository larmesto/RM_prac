// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_laser_scan_matcher:srv/ResetOdom.idl
// generated code does not contain a copyright notice

#ifndef ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_HPP_
#define ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Request __declspec(deprecated)
#endif

namespace ros2_laser_scan_matcher
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetOdom_Request_
{
  using Type = ResetOdom_Request_<ContainerAllocator>;

  explicit ResetOdom_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reset = false;
    }
  }

  explicit ResetOdom_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->reset = false;
    }
  }

  // field types and members
  using _reset_type =
    bool;
  _reset_type reset;

  // setters for named parameter idiom
  Type & set__reset(
    const bool & _arg)
  {
    this->reset = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Request
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Request
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetOdom_Request_ & other) const
  {
    if (this->reset != other.reset) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetOdom_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetOdom_Request_

// alias to use template instance with default allocator
using ResetOdom_Request =
  ros2_laser_scan_matcher::srv::ResetOdom_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_laser_scan_matcher


#ifndef _WIN32
# define DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Response __declspec(deprecated)
#endif

namespace ros2_laser_scan_matcher
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetOdom_Response_
{
  using Type = ResetOdom_Response_<ContainerAllocator>;

  explicit ResetOdom_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit ResetOdom_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Response
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_laser_scan_matcher__srv__ResetOdom_Response
    std::shared_ptr<ros2_laser_scan_matcher::srv::ResetOdom_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetOdom_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetOdom_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetOdom_Response_

// alias to use template instance with default allocator
using ResetOdom_Response =
  ros2_laser_scan_matcher::srv::ResetOdom_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

namespace ros2_laser_scan_matcher
{

namespace srv
{

struct ResetOdom
{
  using Request = ros2_laser_scan_matcher::srv::ResetOdom_Request;
  using Response = ros2_laser_scan_matcher::srv::ResetOdom_Response;
};

}  // namespace srv

}  // namespace ros2_laser_scan_matcher

#endif  // ROS2_LASER_SCAN_MATCHER__SRV__DETAIL__RESET_ODOM__STRUCT_HPP_
