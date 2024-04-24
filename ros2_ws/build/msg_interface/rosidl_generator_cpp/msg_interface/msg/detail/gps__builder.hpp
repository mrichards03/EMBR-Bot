// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msg_interface:msg/Gps.idl
// generated code does not contain a copyright notice

#ifndef MSG_INTERFACE__MSG__DETAIL__GPS__BUILDER_HPP_
#define MSG_INTERFACE__MSG__DETAIL__GPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msg_interface/msg/detail/gps__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msg_interface
{

namespace msg
{

namespace builder
{

class Init_Gps_vel
{
public:
  explicit Init_Gps_vel(::msg_interface::msg::Gps & msg)
  : msg_(msg)
  {}
  ::msg_interface::msg::Gps vel(::msg_interface::msg::Gps::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msg_interface::msg::Gps msg_;
};

class Init_Gps_alt
{
public:
  explicit Init_Gps_alt(::msg_interface::msg::Gps & msg)
  : msg_(msg)
  {}
  Init_Gps_vel alt(::msg_interface::msg::Gps::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_Gps_vel(msg_);
  }

private:
  ::msg_interface::msg::Gps msg_;
};

class Init_Gps_lon
{
public:
  explicit Init_Gps_lon(::msg_interface::msg::Gps & msg)
  : msg_(msg)
  {}
  Init_Gps_alt lon(::msg_interface::msg::Gps::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_Gps_alt(msg_);
  }

private:
  ::msg_interface::msg::Gps msg_;
};

class Init_Gps_lat
{
public:
  Init_Gps_lat()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gps_lon lat(::msg_interface::msg::Gps::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_Gps_lon(msg_);
  }

private:
  ::msg_interface::msg::Gps msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msg_interface::msg::Gps>()
{
  return msg_interface::msg::builder::Init_Gps_lat();
}

}  // namespace msg_interface

#endif  // MSG_INTERFACE__MSG__DETAIL__GPS__BUILDER_HPP_
