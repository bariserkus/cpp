cmake_minimum_required(VERSION 3.22)
project(s08p82)

set(CMAKE_CXX_STANDARD 20)

add_executable(s08p82 main.cpp common.h thread_safe_q.h utils.h)
target_link_libraries(s08p82 pthread)
