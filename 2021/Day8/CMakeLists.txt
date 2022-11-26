cmake_minimum_required(VERSION 3.13)
project(Day2 CXX)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

option(COVERAGE "Generate coverage data" OFF)
if (COVERAGE)
  message("Turning on coverage\n")
  add_compile_options(
    --coverage
    -O0
    -g
  )
  add_link_options("--coverage")
endif()

# Load FetchContent module.
include(FetchContent)
# Declare GoogleTest as the content to fetch
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.1
)

# Fetch GoogleTest amd make build scripts available
if (NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
endif()

#set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
# Force Google Test to link the C/C++ runtimes dynamically when
# building on Visual Studio
# Link:
# * https://github.com/google/googletest/tree/release-1.8.1/googletest#visual-studio-dynamic-vs-static-runtimes
if (MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable( Day8_incMeasurement
                  src/main.cpp
                  src/measurements.cpp
              )

add_executable( Day8_incMeasurement_test
                src/measurements.cpp
                test/measurements_test.cpp
              )

target_include_directories(Day8_incMeasurement_test PUBLIC ./src/)
target_link_libraries(Day8_incMeasurement_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

include(GoogleTest)
gtest_discover_tests(Day8_incMeasurement_test)

