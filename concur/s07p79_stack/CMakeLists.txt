cmake_minimum_required(VERSION 3.22)
project(s07p79)

set(CMAKE_CXX_STANDARD 20)

add_executable(s07p79 main.cpp)
target_link_libraries(s07p79 pthread)
