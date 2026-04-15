// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kinematic_control_pkg:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__FUNCTIONS_H_
#define KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kinematic_control_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "kinematic_control_pkg/msg/detail/reference__struct.h"

/// Initialize msg/Reference message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinematic_control_pkg__msg__Reference
 * )) before or use
 * kinematic_control_pkg__msg__Reference__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__init(kinematic_control_pkg__msg__Reference * msg);

/// Finalize msg/Reference message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
void
kinematic_control_pkg__msg__Reference__fini(kinematic_control_pkg__msg__Reference * msg);

/// Create msg/Reference message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinematic_control_pkg__msg__Reference__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
kinematic_control_pkg__msg__Reference *
kinematic_control_pkg__msg__Reference__create();

/// Destroy msg/Reference message.
/**
 * It calls
 * kinematic_control_pkg__msg__Reference__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
void
kinematic_control_pkg__msg__Reference__destroy(kinematic_control_pkg__msg__Reference * msg);

/// Check for msg/Reference message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__are_equal(const kinematic_control_pkg__msg__Reference * lhs, const kinematic_control_pkg__msg__Reference * rhs);

/// Copy a msg/Reference message.
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
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__copy(
  const kinematic_control_pkg__msg__Reference * input,
  kinematic_control_pkg__msg__Reference * output);

/// Initialize array of msg/Reference messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinematic_control_pkg__msg__Reference__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__Sequence__init(kinematic_control_pkg__msg__Reference__Sequence * array, size_t size);

/// Finalize array of msg/Reference messages.
/**
 * It calls
 * kinematic_control_pkg__msg__Reference__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
void
kinematic_control_pkg__msg__Reference__Sequence__fini(kinematic_control_pkg__msg__Reference__Sequence * array);

/// Create array of msg/Reference messages.
/**
 * It allocates the memory for the array and calls
 * kinematic_control_pkg__msg__Reference__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
kinematic_control_pkg__msg__Reference__Sequence *
kinematic_control_pkg__msg__Reference__Sequence__create(size_t size);

/// Destroy array of msg/Reference messages.
/**
 * It calls
 * kinematic_control_pkg__msg__Reference__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
void
kinematic_control_pkg__msg__Reference__Sequence__destroy(kinematic_control_pkg__msg__Reference__Sequence * array);

/// Check for msg/Reference message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__Sequence__are_equal(const kinematic_control_pkg__msg__Reference__Sequence * lhs, const kinematic_control_pkg__msg__Reference__Sequence * rhs);

/// Copy an array of msg/Reference messages.
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
ROSIDL_GENERATOR_C_PUBLIC_kinematic_control_pkg
bool
kinematic_control_pkg__msg__Reference__Sequence__copy(
  const kinematic_control_pkg__msg__Reference__Sequence * input,
  kinematic_control_pkg__msg__Reference__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KINEMATIC_CONTROL_PKG__MSG__DETAIL__REFERENCE__FUNCTIONS_H_
