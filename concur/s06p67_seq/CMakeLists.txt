cmake_minimum_required(VERSION 3.22)
project(s06p67)

set(CMAKE_CXX_STANDARD 20)

add_executable(s06p67 main.cpp)
target_link_libraries(s06p67 pthread)
