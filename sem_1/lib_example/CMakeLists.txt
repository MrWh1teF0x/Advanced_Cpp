cmake_minimum_required(VERSION 3.10)

set(PROJECT lib_example)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(shapelib)

add_executable(lib_example main.cpp)
target_link_libraries(${PROJECT} PRIVATE shapelib)
target_link_directories(${PROJECT} PRIVATE shapelib)