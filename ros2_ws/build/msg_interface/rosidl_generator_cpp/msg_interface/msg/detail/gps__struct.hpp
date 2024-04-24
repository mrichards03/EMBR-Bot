// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msg_interface:msg/Gps.idl
// generated code does not contain a copyright notice

#ifndef MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_HPP_
#define MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msg_interface__msg__Gps __attribute__((deprecated))
#else
# define DEPRECATED__msg_interface__msg__Gps __declspec(deprecated)
#endif

namespace msg_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gps_
{
  using Type = Gps_<ContainerAllocator>;

  explicit Gps_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lat = 0l;
      this->lon = 0l;
      this->alt = 0l;
      this->vel = 0.0f;
    }
  }

  explicit Gps_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lat = 0l;
      this->lon = 0l;
      this->alt = 0l;
      this->vel = 0.0f;
    }
  }

  // field types and members
  using _lat_type =
    int32_t;
  _lat_type lat;
  using _lon_type =
    int32_t;
  _lon_type lon;
  using _alt_type =
    int32_t;
  _alt_type alt;
  using _vel_type =
    float;
  _vel_type vel;

  // setters for named parameter idiom
  Type & set__lat(
    const int32_t & _arg)
  {
    this->lat = _arg;
    return *this;
  }
  Type & set__lon(
    const int32_t & _arg)
  {
    this->lon = _arg;
    return *this;
  }
  Type & set__alt(
    const int32_t & _arg)
  {
    this->alt = _arg;
    return *this;
  }
  Type & set__vel(
    const float & _arg)
  {
    this->vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msg_interface::msg::Gps_<ContainerAllocator> *;
  using ConstRawPtr =
    const msg_interface::msg::Gps_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msg_interface::msg::Gps_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msg_interface::msg::Gps_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msg_interface::msg::Gps_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msg_interface::msg::Gps_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msg_interface::msg::Gps_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msg_interface::msg::Gps_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msg_interface::msg::Gps_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msg_interface::msg::Gps_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msg_interface__msg__Gps
    std::shared_ptr<msg_interface::msg::Gps_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msg_interface__msg__Gps
    std::shared_ptr<msg_interface::msg::Gps_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gps_ & other) const
  {
    if (this->lat != other.lat) {
      return false;
    }
    if (this->lon != other.lon) {
      return false;
    }
    if (this->alt != other.alt) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gps_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gps_

// alias to use template instance with default allocator
using Gps =
  msg_interface::msg::Gps_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msg_interface

#endif  // MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_HPP_
