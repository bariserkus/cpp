cmake_minimum_required(VERSION 3.22)
project(s05p55)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")
#set(CMAKE_CXX_FLAGS "-fcoroutines")

add_executable(s05p55 main.cpp)
