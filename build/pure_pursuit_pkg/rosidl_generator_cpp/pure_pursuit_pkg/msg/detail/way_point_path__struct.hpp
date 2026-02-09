// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice

#ifndef PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_HPP_
#define PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'closed_path'
#include "std_msgs/msg/detail/bool__struct.hpp"
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pure_pursuit_pkg__msg__WayPointPath __attribute__((deprecated))
#else
# define DEPRECATED__pure_pursuit_pkg__msg__WayPointPath __declspec(deprecated)
#endif

namespace pure_pursuit_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WayPointPath_
{
  using Type = WayPointPath_<ContainerAllocator>;

  explicit WayPointPath_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : closed_path(_init)
  {
    (void)_init;
  }

  explicit WayPointPath_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : closed_path(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _closed_path_type =
    std_msgs::msg::Bool_<ContainerAllocator>;
  _closed_path_type closed_path;
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__closed_path(
    const std_msgs::msg::Bool_<ContainerAllocator> & _arg)
  {
    this->closed_path = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> *;
  using ConstRawPtr =
    const pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pure_pursuit_pkg__msg__WayPointPath
    std::shared_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pure_pursuit_pkg__msg__WayPointPath
    std::shared_ptr<pure_pursuit_pkg::msg::WayPointPath_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WayPointPath_ & other) const
  {
    if (this->closed_path != other.closed_path) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const WayPointPath_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WayPointPath_

// alias to use template instance with default allocator
using WayPointPath =
  pure_pursuit_pkg::msg::WayPointPath_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pure_pursuit_pkg

#endif  // PURE_PURSUIT_PKG__MSG__DETAIL__WAY_POINT_PATH__STRUCT_HPP_
