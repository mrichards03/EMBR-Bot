// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from msg_interface:msg/Gps.idl
// generated code does not contain a copyright notice

#ifndef MSG_INTERFACE__MSG__DETAIL__GPS__FUNCTIONS_H_
#define MSG_INTERFACE__MSG__DETAIL__GPS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "msg_interface/msg/rosidl_generator_c__visibility_control.h"

#include "msg_interface/msg/detail/gps__struct.h"

/// Initialize msg/Gps message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msg_interface__msg__Gps
 * )) before or use
 * msg_interface__msg__Gps__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__init(msg_interface__msg__Gps * msg);

/// Finalize msg/Gps message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
void
msg_interface__msg__Gps__fini(msg_interface__msg__Gps * msg);

/// Create msg/Gps message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msg_interface__msg__Gps__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
msg_interface__msg__Gps *
msg_interface__msg__Gps__create();

/// Destroy msg/Gps message.
/**
 * It calls
 * msg_interface__msg__Gps__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
void
msg_interface__msg__Gps__destroy(msg_interface__msg__Gps * msg);

/// Check for msg/Gps message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__are_equal(const msg_interface__msg__Gps * lhs, const msg_interface__msg__Gps * rhs);

/// Copy a msg/Gps message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__copy(
  const msg_interface__msg__Gps * input,
  msg_interface__msg__Gps * output);

/// Initialize array of msg/Gps messages.
/**
 * It allocates the memory for the number of elements and calls
 * msg_interface__msg__Gps__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__Sequence__init(msg_interface__msg__Gps__Sequence * array, size_t size);

/// Finalize array of msg/Gps messages.
/**
 * It calls
 * msg_interface__msg__Gps__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
void
msg_interface__msg__Gps__Sequence__fini(msg_interface__msg__Gps__Sequence * array);

/// Create array of msg/Gps messages.
/**
 * It allocates the memory for the array and calls
 * msg_interface__msg__Gps__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
msg_interface__msg__Gps__Sequence *
msg_interface__msg__Gps__Sequence__create(size_t size);

/// Destroy array of msg/Gps messages.
/**
 * It calls
 * msg_interface__msg__Gps__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
void
msg_interface__msg__Gps__Sequence__destroy(msg_interface__msg__Gps__Sequence * array);

/// Check for msg/Gps message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__Sequence__are_equal(const msg_interface__msg__Gps__Sequence * lhs, const msg_interface__msg__Gps__Sequence * rhs);

/// Copy an array of msg/Gps messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msg_interface
bool
msg_interface__msg__Gps__Sequence__copy(
  const msg_interface__msg__Gps__Sequence * input,
  msg_interface__msg__Gps__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MSG_INTERFACE__MSG__DETAIL__GPS__FUNCTIONS_H_
