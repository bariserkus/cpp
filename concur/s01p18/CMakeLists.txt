cmake_minimum_required(VERSION 3.22)
project(s01p18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(s01p18 main.cpp)
set(CMAKE_CXX_FLAGS "-ltbb")
