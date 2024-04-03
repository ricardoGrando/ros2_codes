cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(publisher_example src/publisher.cpp)
ament_target_dependencies(publisher_example rclcpp example_interfaces)

add_executable(subscriber_example src/subscriber.cpp)
ament_target_dependencies(subscriber_example rclcpp example_interfaces)

install(TARGETS
 cpp_node
 publisher_example
 subscriber_example
 DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
 launch
 DESTINATION share/${PROJECT_NAME}
)

ament_package()
