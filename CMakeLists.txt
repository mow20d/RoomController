cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(TEST LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6 
)
FetchContent_MakeAvailable(googletest)

# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

add_executable(${PROJECT_NAME} src/RoomController.cpp 
src/Sensor.cpp test/test_example.cpp)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# Testing
enable_testing()

#include headers
include_directories(include)