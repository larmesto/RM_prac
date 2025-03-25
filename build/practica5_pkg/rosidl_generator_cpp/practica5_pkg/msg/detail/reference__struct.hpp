// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from practica5_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_HPP_
#define PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__practica5_pkg__msg__Reference __attribute__((deprecated))
#else
# define DEPRECATED__practica5_pkg__msg__Reference __declspec(deprecated)
#endif

namespace practica5_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Reference_
{
  using Type = Reference_<ContainerAllocator>;

  explicit Reference_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    velocity(_init)
  {
    (void)_init;
  }

  explicit Reference_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose(_alloc, _init),
    velocity(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _velocity_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _velocity_type velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    practica5_pkg::msg::Reference_<ContainerAllocator> *;
  using ConstRawPtr =
    const practica5_pkg::msg::Reference_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<practica5_pkg::msg::Reference_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<practica5_pkg::msg::Reference_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      practica5_pkg::msg::Reference_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<practica5_pkg::msg::Reference_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      practica5_pkg::msg::Reference_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<practica5_pkg::msg::Reference_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<practica5_pkg::msg::Reference_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<practica5_pkg::msg::Reference_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__practica5_pkg__msg__Reference
    std::shared_ptr<practica5_pkg::msg::Reference_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__practica5_pkg__msg__Reference
    std::shared_ptr<practica5_pkg::msg::Reference_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reference_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reference_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reference_

// alias to use template instance with default allocator
using Reference =
  practica5_pkg::msg::Reference_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace practica5_pkg

#endif  // PRACTICA5_PKG__MSG__DETAIL__REFERENCE__STRUCT_HPP_
