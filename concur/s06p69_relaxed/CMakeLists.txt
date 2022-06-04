set(PROJECT_NAME "s06p69")

cmake_minimum_required(VERSION 3.22)
project(PROJECT_NAME)
set(CMAKE_CXX_STANDARD 20)
add_executable(PROJECT_NAME main.cpp)
target_link_libraries(PROJECT_NAME pthread)
