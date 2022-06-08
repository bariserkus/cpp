cmake_minimum_required(VERSION 3.22)
project(s07p77)

set(CMAKE_CXX_STANDARD 20)

add_executable(s07p77 main.cpp)
target_link_libraries(s07p77 pthread)
