// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice

#ifndef PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__FUNCTIONS_H_
#define PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "practica4_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "practica4_pkg/srv/detail/reset_map__struct.h"

/// Initialize srv/ResetMap message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * practica4_pkg__srv__ResetMap_Request
 * )) before or use
 * practica4_pkg__srv__ResetMap_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__init(practica4_pkg__srv__ResetMap_Request * msg);

/// Finalize srv/ResetMap message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Request__fini(practica4_pkg__srv__ResetMap_Request * msg);

/// Create srv/ResetMap message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * practica4_pkg__srv__ResetMap_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
practica4_pkg__srv__ResetMap_Request *
practica4_pkg__srv__ResetMap_Request__create();

/// Destroy srv/ResetMap message.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Request__destroy(practica4_pkg__srv__ResetMap_Request * msg);

/// Check for srv/ResetMap message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__are_equal(const practica4_pkg__srv__ResetMap_Request * lhs, const practica4_pkg__srv__ResetMap_Request * rhs);

/// Copy a srv/ResetMap message.
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
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__copy(
  const practica4_pkg__srv__ResetMap_Request * input,
  practica4_pkg__srv__ResetMap_Request * output);

/// Initialize array of srv/ResetMap messages.
/**
 * It allocates the memory for the number of elements and calls
 * practica4_pkg__srv__ResetMap_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__Sequence__init(practica4_pkg__srv__ResetMap_Request__Sequence * array, size_t size);

/// Finalize array of srv/ResetMap messages.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Request__Sequence__fini(practica4_pkg__srv__ResetMap_Request__Sequence * array);

/// Create array of srv/ResetMap messages.
/**
 * It allocates the memory for the array and calls
 * practica4_pkg__srv__ResetMap_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
practica4_pkg__srv__ResetMap_Request__Sequence *
practica4_pkg__srv__ResetMap_Request__Sequence__create(size_t size);

/// Destroy array of srv/ResetMap messages.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Request__Sequence__destroy(practica4_pkg__srv__ResetMap_Request__Sequence * array);

/// Check for srv/ResetMap message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__Sequence__are_equal(const practica4_pkg__srv__ResetMap_Request__Sequence * lhs, const practica4_pkg__srv__ResetMap_Request__Sequence * rhs);

/// Copy an array of srv/ResetMap messages.
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
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Request__Sequence__copy(
  const practica4_pkg__srv__ResetMap_Request__Sequence * input,
  practica4_pkg__srv__ResetMap_Request__Sequence * output);

/// Initialize srv/ResetMap message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * practica4_pkg__srv__ResetMap_Response
 * )) before or use
 * practica4_pkg__srv__ResetMap_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__init(practica4_pkg__srv__ResetMap_Response * msg);

/// Finalize srv/ResetMap message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Response__fini(practica4_pkg__srv__ResetMap_Response * msg);

/// Create srv/ResetMap message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * practica4_pkg__srv__ResetMap_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
practica4_pkg__srv__ResetMap_Response *
practica4_pkg__srv__ResetMap_Response__create();

/// Destroy srv/ResetMap message.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Response__destroy(practica4_pkg__srv__ResetMap_Response * msg);

/// Check for srv/ResetMap message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__are_equal(const practica4_pkg__srv__ResetMap_Response * lhs, const practica4_pkg__srv__ResetMap_Response * rhs);

/// Copy a srv/ResetMap message.
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
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__copy(
  const practica4_pkg__srv__ResetMap_Response * input,
  practica4_pkg__srv__ResetMap_Response * output);

/// Initialize array of srv/ResetMap messages.
/**
 * It allocates the memory for the number of elements and calls
 * practica4_pkg__srv__ResetMap_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__Sequence__init(practica4_pkg__srv__ResetMap_Response__Sequence * array, size_t size);

/// Finalize array of srv/ResetMap messages.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Response__Sequence__fini(practica4_pkg__srv__ResetMap_Response__Sequence * array);

/// Create array of srv/ResetMap messages.
/**
 * It allocates the memory for the array and calls
 * practica4_pkg__srv__ResetMap_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
practica4_pkg__srv__ResetMap_Response__Sequence *
practica4_pkg__srv__ResetMap_Response__Sequence__create(size_t size);

/// Destroy array of srv/ResetMap messages.
/**
 * It calls
 * practica4_pkg__srv__ResetMap_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
void
practica4_pkg__srv__ResetMap_Response__Sequence__destroy(practica4_pkg__srv__ResetMap_Response__Sequence * array);

/// Check for srv/ResetMap message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__Sequence__are_equal(const practica4_pkg__srv__ResetMap_Response__Sequence * lhs, const practica4_pkg__srv__ResetMap_Response__Sequence * rhs);

/// Copy an array of srv/ResetMap messages.
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
ROSIDL_GENERATOR_C_PUBLIC_practica4_pkg
bool
practica4_pkg__srv__ResetMap_Response__Sequence__copy(
  const practica4_pkg__srv__ResetMap_Response__Sequence * input,
  practica4_pkg__srv__ResetMap_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PRACTICA4_PKG__SRV__DETAIL__RESET_MAP__FUNCTIONS_H_
