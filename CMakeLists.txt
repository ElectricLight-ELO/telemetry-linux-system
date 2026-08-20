cmake_minimum_required(VERSION 3.20)
project(telemetry_linux_system CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build unit tests" ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(libs/core)
add_subdirectory(apps/exporter)
add_subdirectory(apps/watchdog)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()