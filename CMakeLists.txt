cmake_minimum_required(VERSION 3.21)

project(jpeg_lite)

find_package(SDL2 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(jpeg_lite main.cpp)

target_include_directories(jpeg_lite PRIVATE include)

add_subdirectory(libs)
target_link_libraries(jpeg_lite
        PRIVATE GSL
        PRIVATE magic_enum
        PRIVATE argparse)

add_subdirectory(helper)

add_subdirectory(decoder)

add_subdirectory(tests)

target_link_libraries(jpeg_lite PRIVATE SDL2::SDL2 SDL2::SDL2main)
# use custom entry point
target_compile_definitions(jpeg_lite PRIVATE -DSDL_MAIN_HANDLED)

