cmake_minimum_required(VERSION 3.22)
project(s04p42)
set(CMAKE_CXX_STANDARD 20)
find_package(TBB REQUIRED)
add_executable(s04p42 main.cpp)
target_link_libraries(s04p42 tbb)
#set(CMAKE_CXX_FLAGS "-pthread")


