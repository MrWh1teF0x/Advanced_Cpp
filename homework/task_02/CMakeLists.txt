cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME task_02)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(typelist INTERFACE
        src/typelist.hpp
)

target_include_directories(typelist INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB PROJECT_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp ${PROJECT_SOURCES})
