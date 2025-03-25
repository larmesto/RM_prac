// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from practica4_pkg:srv/ResetMap.idl
// generated code does not contain a copyright notice
#include "practica4_pkg/srv/detail/reset_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
practica4_pkg__srv__ResetMap_Request__init(practica4_pkg__srv__ResetMap_Request * msg)
{
  if (!msg) {
    return false;
  }
  // reset_req
  return true;
}

void
practica4_pkg__srv__ResetMap_Request__fini(practica4_pkg__srv__ResetMap_Request * msg)
{
  if (!msg) {
    return;
  }
  // reset_req
}

bool
practica4_pkg__srv__ResetMap_Request__are_equal(const practica4_pkg__srv__ResetMap_Request * lhs, const practica4_pkg__srv__ResetMap_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // reset_req
  if (lhs->reset_req != rhs->reset_req) {
    return false;
  }
  return true;
}

bool
practica4_pkg__srv__ResetMap_Request__copy(
  const practica4_pkg__srv__ResetMap_Request * input,
  practica4_pkg__srv__ResetMap_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // reset_req
  output->reset_req = input->reset_req;
  return true;
}

practica4_pkg__srv__ResetMap_Request *
practica4_pkg__srv__ResetMap_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Request * msg = (practica4_pkg__srv__ResetMap_Request *)allocator.allocate(sizeof(practica4_pkg__srv__ResetMap_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(practica4_pkg__srv__ResetMap_Request));
  bool success = practica4_pkg__srv__ResetMap_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
practica4_pkg__srv__ResetMap_Request__destroy(practica4_pkg__srv__ResetMap_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    practica4_pkg__srv__ResetMap_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
practica4_pkg__srv__ResetMap_Request__Sequence__init(practica4_pkg__srv__ResetMap_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Request * data = NULL;

  if (size) {
    data = (practica4_pkg__srv__ResetMap_Request *)allocator.zero_allocate(size, sizeof(practica4_pkg__srv__ResetMap_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = practica4_pkg__srv__ResetMap_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        practica4_pkg__srv__ResetMap_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
practica4_pkg__srv__ResetMap_Request__Sequence__fini(practica4_pkg__srv__ResetMap_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      practica4_pkg__srv__ResetMap_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

practica4_pkg__srv__ResetMap_Request__Sequence *
practica4_pkg__srv__ResetMap_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Request__Sequence * array = (practica4_pkg__srv__ResetMap_Request__Sequence *)allocator.allocate(sizeof(practica4_pkg__srv__ResetMap_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = practica4_pkg__srv__ResetMap_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
practica4_pkg__srv__ResetMap_Request__Sequence__destroy(practica4_pkg__srv__ResetMap_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    practica4_pkg__srv__ResetMap_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
practica4_pkg__srv__ResetMap_Request__Sequence__are_equal(const practica4_pkg__srv__ResetMap_Request__Sequence * lhs, const practica4_pkg__srv__ResetMap_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!practica4_pkg__srv__ResetMap_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
practica4_pkg__srv__ResetMap_Request__Sequence__copy(
  const practica4_pkg__srv__ResetMap_Request__Sequence * input,
  practica4_pkg__srv__ResetMap_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(practica4_pkg__srv__ResetMap_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    practica4_pkg__srv__ResetMap_Request * data =
      (practica4_pkg__srv__ResetMap_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!practica4_pkg__srv__ResetMap_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          practica4_pkg__srv__ResetMap_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!practica4_pkg__srv__ResetMap_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

bool
practica4_pkg__srv__ResetMap_Response__init(practica4_pkg__srv__ResetMap_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    practica4_pkg__srv__ResetMap_Response__fini(msg);
    return false;
  }
  return true;
}

void
practica4_pkg__srv__ResetMap_Response__fini(practica4_pkg__srv__ResetMap_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
practica4_pkg__srv__ResetMap_Response__are_equal(const practica4_pkg__srv__ResetMap_Response * lhs, const practica4_pkg__srv__ResetMap_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
practica4_pkg__srv__ResetMap_Response__copy(
  const practica4_pkg__srv__ResetMap_Response * input,
  practica4_pkg__srv__ResetMap_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

practica4_pkg__srv__ResetMap_Response *
practica4_pkg__srv__ResetMap_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Response * msg = (practica4_pkg__srv__ResetMap_Response *)allocator.allocate(sizeof(practica4_pkg__srv__ResetMap_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(practica4_pkg__srv__ResetMap_Response));
  bool success = practica4_pkg__srv__ResetMap_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
practica4_pkg__srv__ResetMap_Response__destroy(practica4_pkg__srv__ResetMap_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    practica4_pkg__srv__ResetMap_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
practica4_pkg__srv__ResetMap_Response__Sequence__init(practica4_pkg__srv__ResetMap_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Response * data = NULL;

  if (size) {
    data = (practica4_pkg__srv__ResetMap_Response *)allocator.zero_allocate(size, sizeof(practica4_pkg__srv__ResetMap_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = practica4_pkg__srv__ResetMap_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        practica4_pkg__srv__ResetMap_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
practica4_pkg__srv__ResetMap_Response__Sequence__fini(practica4_pkg__srv__ResetMap_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      practica4_pkg__srv__ResetMap_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

practica4_pkg__srv__ResetMap_Response__Sequence *
practica4_pkg__srv__ResetMap_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  practica4_pkg__srv__ResetMap_Response__Sequence * array = (practica4_pkg__srv__ResetMap_Response__Sequence *)allocator.allocate(sizeof(practica4_pkg__srv__ResetMap_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = practica4_pkg__srv__ResetMap_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
practica4_pkg__srv__ResetMap_Response__Sequence__destroy(practica4_pkg__srv__ResetMap_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    practica4_pkg__srv__ResetMap_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
practica4_pkg__srv__ResetMap_Response__Sequence__are_equal(const practica4_pkg__srv__ResetMap_Response__Sequence * lhs, const practica4_pkg__srv__ResetMap_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!practica4_pkg__srv__ResetMap_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
practica4_pkg__srv__ResetMap_Response__Sequence__copy(
  const practica4_pkg__srv__ResetMap_Response__Sequence * input,
  practica4_pkg__srv__ResetMap_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(practica4_pkg__srv__ResetMap_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    practica4_pkg__srv__ResetMap_Response * data =
      (practica4_pkg__srv__ResetMap_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!practica4_pkg__srv__ResetMap_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          practica4_pkg__srv__ResetMap_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!practica4_pkg__srv__ResetMap_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
