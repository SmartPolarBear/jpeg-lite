CMAKE_MINIMUM_REQUIRED(VERSION 3.21)

target_sources(jpeg_lite
        PRIVATE utility.cpp
        PRIVATE huffman_tree.cpp)