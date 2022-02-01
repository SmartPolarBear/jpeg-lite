cmake_minimum_required(VERSION 3.21)
project(jpeg_lite2)

set(CMAKE_CXX_STANDARD 23)

add_executable(jpeg_lite2 main.cpp)

target_include_directories(include)

add_subdirectory(common)

add_subdirectory(decoder)

add_subdirectory(tests)