cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME task_01)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)
find_library(lib ./lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE lib)
target_include_directories(${PROJECT_NAME} PRIVATE lib)