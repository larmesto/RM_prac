# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_practica4_pkg_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED practica4_pkg_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(practica4_pkg_FOUND FALSE)
  elseif(NOT practica4_pkg_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(practica4_pkg_FOUND FALSE)
  endif()
  return()
endif()
set(_practica4_pkg_CONFIG_INCLUDED TRUE)

# output package information
if(NOT practica4_pkg_FIND_QUIETLY)
  message(STATUS "Found practica4_pkg: 0.0.0 (${practica4_pkg_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'practica4_pkg' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${practica4_pkg_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(practica4_pkg_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${practica4_pkg_DIR}/${_extra}")
endforeach()
