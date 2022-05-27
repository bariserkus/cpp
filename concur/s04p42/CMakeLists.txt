cmake_minimum_required(VERSION 3.22)
project(s04p42)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")

set(CMAKE_CXX_FLAGS "-ltbb")
add_executable(s04p42 main.cpp)


