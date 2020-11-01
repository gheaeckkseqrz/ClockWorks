cmake_minimum_required(VERSION 3.0)
project(ClockWorks)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(ClockWorks main.cpp)

enable_testing()
