# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_drawing_circles_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED drawing_circles_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(drawing_circles_FOUND FALSE)
  elseif(NOT drawing_circles_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(drawing_circles_FOUND FALSE)
  endif()
  return()
endif()
set(_drawing_circles_CONFIG_INCLUDED TRUE)

# output package information
if(NOT drawing_circles_FIND_QUIETLY)
  message(STATUS "Found drawing_circles: 0.0.0 (${drawing_circles_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'drawing_circles' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${drawing_circles_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(drawing_circles_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${drawing_circles_DIR}/${_extra}")
endforeach()
