cmake_minimum_required(VERSION 3.25)
project(main LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main 
    main.cpp
    compressor.cpp
    huffman_tree.cpp
    
)
