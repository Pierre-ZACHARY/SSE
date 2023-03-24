cmake_minimum_required(VERSION 3.24)
project(SSE_TP1 C)

add_compile_options(-Wall -msse4.1 -O2)
set(CMAKE_C_STANDARD 11)

enable_testing()
add_subdirectory(TP1-files)
add_subdirectory(TP2-files)