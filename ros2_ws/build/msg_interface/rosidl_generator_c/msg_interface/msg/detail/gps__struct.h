// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msg_interface:msg/Gps.idl
// generated code does not contain a copyright notice

#ifndef MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_H_
#define MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Gps in the package msg_interface.
typedef struct msg_interface__msg__Gps
{
  int32_t lat;
  int32_t lon;
  int32_t alt;
  float vel;
} msg_interface__msg__Gps;

// Struct for a sequence of msg_interface__msg__Gps.
typedef struct msg_interface__msg__Gps__Sequence
{
  msg_interface__msg__Gps * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msg_interface__msg__Gps__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSG_INTERFACE__MSG__DETAIL__GPS__STRUCT_H_
