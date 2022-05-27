cmake_minimum_required(VERSION 3.22)
project(s01p08)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(s01p08 main.cpp common.h)
