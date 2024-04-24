// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msg_interface:msg/Gps.idl
// generated code does not contain a copyright notice

#ifndef MSG_INTERFACE__MSG__DETAIL__GPS__TRAITS_HPP_
#define MSG_INTERFACE__MSG__DETAIL__GPS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msg_interface/msg/detail/gps__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msg_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gps & msg,
  std::ostream & out)
{
  out << "{";
  // member: lat
  {
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << ", ";
  }

  // member: lon
  {
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << ", ";
  }

  // member: alt
  {
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << ", ";
  }

  // member: vel
  {
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gps & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lat: ";
    rosidl_generator_traits::value_to_yaml(msg.lat, out);
    out << "\n";
  }

  // member: lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lon: ";
    rosidl_generator_traits::value_to_yaml(msg.lon, out);
    out << "\n";
  }

  // member: alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alt: ";
    rosidl_generator_traits::value_to_yaml(msg.alt, out);
    out << "\n";
  }

  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gps & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msg_interface

namespace rosidl_generator_traits
{

[[deprecated("use msg_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msg_interface::msg::Gps & msg,
  std::ostream & out, size_t indentation = 0)
{
  msg_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msg_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const msg_interface::msg::Gps & msg)
{
  return msg_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msg_interface::msg::Gps>()
{
  return "msg_interface::msg::Gps";
}

template<>
inline const char * name<msg_interface::msg::Gps>()
{
  return "msg_interface/msg/Gps";
}

template<>
struct has_fixed_size<msg_interface::msg::Gps>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msg_interface::msg::Gps>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msg_interface::msg::Gps>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSG_INTERFACE__MSG__DETAIL__GPS__TRAITS_HPP_
