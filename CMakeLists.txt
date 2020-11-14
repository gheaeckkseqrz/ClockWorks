cmake_minimum_required(VERSION 3.13.4)
project(ClockWorks)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_executable(ClockWorks main.cpp)
add_subdirectory(GUI)

enable_testing()
add_subdirectory(tests)
