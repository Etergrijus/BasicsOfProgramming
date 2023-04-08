cmake_minimum_required(VERSION 3.16)
project(Vector C)

set(CMAKE_C_STANDARD 99)

add_executable(Vector main.c)

add_library(vec libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)

target_link_libraries(Vector vec)