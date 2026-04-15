// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinematic_control_pkg:msg/Reference.idl
// generated code does not contain a copyright notice
#include "kinematic_control_pkg/msg/detail/reference__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
kinematic_control_pkg__msg__Reference__init(kinematic_control_pkg__msg__Reference * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    kinematic_control_pkg__msg__Reference__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    kinematic_control_pkg__msg__Reference__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__init(&msg->velocity)) {
    kinematic_control_pkg__msg__Reference__fini(msg);
    return false;
  }
  return true;
}

void
kinematic_control_pkg__msg__Reference__fini(kinematic_control_pkg__msg__Reference * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // velocity
  geometry_msgs__msg__Twist__fini(&msg->velocity);
}

bool
kinematic_control_pkg__msg__Reference__are_equal(const kinematic_control_pkg__msg__Reference * lhs, const kinematic_control_pkg__msg__Reference * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  return true;
}

bool
kinematic_control_pkg__msg__Reference__copy(
  const kinematic_control_pkg__msg__Reference * input,
  kinematic_control_pkg__msg__Reference * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  return true;
}

kinematic_control_pkg__msg__Reference *
kinematic_control_pkg__msg__Reference__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematic_control_pkg__msg__Reference * msg = (kinematic_control_pkg__msg__Reference *)allocator.allocate(sizeof(kinematic_control_pkg__msg__Reference), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinematic_control_pkg__msg__Reference));
  bool success = kinematic_control_pkg__msg__Reference__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinematic_control_pkg__msg__Reference__destroy(kinematic_control_pkg__msg__Reference * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinematic_control_pkg__msg__Reference__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinematic_control_pkg__msg__Reference__Sequence__init(kinematic_control_pkg__msg__Reference__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematic_control_pkg__msg__Reference * data = NULL;

  if (size) {
    data = (kinematic_control_pkg__msg__Reference *)allocator.zero_allocate(size, sizeof(kinematic_control_pkg__msg__Reference), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinematic_control_pkg__msg__Reference__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinematic_control_pkg__msg__Reference__fini(&data[i - 1]);
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
kinematic_control_pkg__msg__Reference__Sequence__fini(kinematic_control_pkg__msg__Reference__Sequence * array)
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
      kinematic_control_pkg__msg__Reference__fini(&array->data[i]);
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

kinematic_control_pkg__msg__Reference__Sequence *
kinematic_control_pkg__msg__Reference__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematic_control_pkg__msg__Reference__Sequence * array = (kinematic_control_pkg__msg__Reference__Sequence *)allocator.allocate(sizeof(kinematic_control_pkg__msg__Reference__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinematic_control_pkg__msg__Reference__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinematic_control_pkg__msg__Reference__Sequence__destroy(kinematic_control_pkg__msg__Reference__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinematic_control_pkg__msg__Reference__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinematic_control_pkg__msg__Reference__Sequence__are_equal(const kinematic_control_pkg__msg__Reference__Sequence * lhs, const kinematic_control_pkg__msg__Reference__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinematic_control_pkg__msg__Reference__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinematic_control_pkg__msg__Reference__Sequence__copy(
  const kinematic_control_pkg__msg__Reference__Sequence * input,
  kinematic_control_pkg__msg__Reference__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinematic_control_pkg__msg__Reference);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinematic_control_pkg__msg__Reference * data =
      (kinematic_control_pkg__msg__Reference *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinematic_control_pkg__msg__Reference__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinematic_control_pkg__msg__Reference__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinematic_control_pkg__msg__Reference__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
