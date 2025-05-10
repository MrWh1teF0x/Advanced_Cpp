cmake_minimum_required(VERSION 3.10)

set(PROJECT lib)
project(${PROJECT})

set(HEADERS
  manager.h
  user.h
  group.h
)

set(SOURCES
  manager.cpp
  user.cpp
  group.cpp
)

add_library(${PROJECT} ${SOURCES} ${HEADERS})