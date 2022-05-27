cmake_minimum_required(VERSION 3.22)
project(project03)

set(CMAKE_CXX_STANDARD 17)

add_executable(project03 main.cpp User.cpp User.h Admin.cpp Admin.h Customer.cpp Customer.h)
