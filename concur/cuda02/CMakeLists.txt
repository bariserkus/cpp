cmake_minimum_required(VERSION 3.22)
project(cuda02 CUDA)

set(CMAKE_CUDA_STANDARD 20)

add_executable(cuda02 main.cu)

set_target_properties(cuda02 PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
