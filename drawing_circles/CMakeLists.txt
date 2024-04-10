cmake_minimum_required(VERSION 3.8)
project(drawing_circles)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

set(dependencies "geometry_msgs" "rclcpp")

add_executable(dr_circles_node src/dr_circles_node.cpp)
ament_target_dependencies(dr_circles_node ${dependencies})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)


  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  dr_circles_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
