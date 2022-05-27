cmake_minimum_required(VERSION 3.22)
project(project01)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-pthread")

add_executable(project01 main.cpp)
