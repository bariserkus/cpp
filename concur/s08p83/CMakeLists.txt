cmake_minimum_required(VERSION 3.22)
project(s08p83)

set(CMAKE_CXX_STANDARD 20)

add_executable(s08p83 main.cpp common.h thread_safe_q.h utils.h)
target_link_libraries(s08p83 pthread)
