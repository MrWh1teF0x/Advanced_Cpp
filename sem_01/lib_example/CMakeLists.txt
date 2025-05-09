cmake_minimum_required(VERSION 3.10)

set(PROJECT lib_example)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(shapelib)
find_library(shapelib ./shapelib)

add_executable(lib_example main.cpp)

target_link_libraries(${PROJECT} PRIVATE shapelib)
target_include_directories(${PROJECT} PRIVATE shapelib)