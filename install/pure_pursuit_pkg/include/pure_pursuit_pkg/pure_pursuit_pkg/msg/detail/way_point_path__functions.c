// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pure_pursuit_pkg:msg/WayPointPath.idl
// generated code does not contain a copyright notice
#include "pure_pursuit_pkg/msg/detail/way_point_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `closed_path`
#include "std_msgs/msg/detail/bool__functions.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
pure_pursuit_pkg__msg__WayPointPath__init(pure_pursuit_pkg__msg__WayPointPath * msg)
{
  if (!msg) {
    return false;
  }
  // closed_path
  if (!std_msgs__msg__Bool__init(&msg->closed_path)) {
    pure_pursuit_pkg__msg__WayPointPath__fini(msg);
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->points, 0)) {
    pure_pursuit_pkg__msg__WayPointPath__fini(msg);
    return false;
  }
  return true;
}

void
pure_pursuit_pkg__msg__WayPointPath__fini(pure_pursuit_pkg__msg__WayPointPath * msg)
{
  if (!msg) {
    return;
  }
  // closed_path
  std_msgs__msg__Bool__fini(&msg->closed_path);
  // points
  geometry_msgs__msg__Point__Sequence__fini(&msg->points);
}

bool
pure_pursuit_pkg__msg__WayPointPath__are_equal(const pure_pursuit_pkg__msg__WayPointPath * lhs, const pure_pursuit_pkg__msg__WayPointPath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // closed_path
  if (!std_msgs__msg__Bool__are_equal(
      &(lhs->closed_path), &(rhs->closed_path)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
pure_pursuit_pkg__msg__WayPointPath__copy(
  const pure_pursuit_pkg__msg__WayPointPath * input,
  pure_pursuit_pkg__msg__WayPointPath * output)
{
  if (!input || !output) {
    return false;
  }
  // closed_path
  if (!std_msgs__msg__Bool__copy(
      &(input->closed_path), &(output->closed_path)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

pure_pursuit_pkg__msg__WayPointPath *
pure_pursuit_pkg__msg__WayPointPath__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pure_pursuit_pkg__msg__WayPointPath * msg = (pure_pursuit_pkg__msg__WayPointPath *)allocator.allocate(sizeof(pure_pursuit_pkg__msg__WayPointPath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pure_pursuit_pkg__msg__WayPointPath));
  bool success = pure_pursuit_pkg__msg__WayPointPath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pure_pursuit_pkg__msg__WayPointPath__destroy(pure_pursuit_pkg__msg__WayPointPath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pure_pursuit_pkg__msg__WayPointPath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pure_pursuit_pkg__msg__WayPointPath__Sequence__init(pure_pursuit_pkg__msg__WayPointPath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pure_pursuit_pkg__msg__WayPointPath * data = NULL;

  if (size) {
    data = (pure_pursuit_pkg__msg__WayPointPath *)allocator.zero_allocate(size, sizeof(pure_pursuit_pkg__msg__WayPointPath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pure_pursuit_pkg__msg__WayPointPath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pure_pursuit_pkg__msg__WayPointPath__fini(&data[i - 1]);
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
pure_pursuit_pkg__msg__WayPointPath__Sequence__fini(pure_pursuit_pkg__msg__WayPointPath__Sequence * array)
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
      pure_pursuit_pkg__msg__WayPointPath__fini(&array->data[i]);
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

pure_pursuit_pkg__msg__WayPointPath__Sequence *
pure_pursuit_pkg__msg__WayPointPath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pure_pursuit_pkg__msg__WayPointPath__Sequence * array = (pure_pursuit_pkg__msg__WayPointPath__Sequence *)allocator.allocate(sizeof(pure_pursuit_pkg__msg__WayPointPath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pure_pursuit_pkg__msg__WayPointPath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pure_pursuit_pkg__msg__WayPointPath__Sequence__destroy(pure_pursuit_pkg__msg__WayPointPath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pure_pursuit_pkg__msg__WayPointPath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pure_pursuit_pkg__msg__WayPointPath__Sequence__are_equal(const pure_pursuit_pkg__msg__WayPointPath__Sequence * lhs, const pure_pursuit_pkg__msg__WayPointPath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pure_pursuit_pkg__msg__WayPointPath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pure_pursuit_pkg__msg__WayPointPath__Sequence__copy(
  const pure_pursuit_pkg__msg__WayPointPath__Sequence * input,
  pure_pursuit_pkg__msg__WayPointPath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pure_pursuit_pkg__msg__WayPointPath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pure_pursuit_pkg__msg__WayPointPath * data =
      (pure_pursuit_pkg__msg__WayPointPath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pure_pursuit_pkg__msg__WayPointPath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pure_pursuit_pkg__msg__WayPointPath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pure_pursuit_pkg__msg__WayPointPath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
