cmake_minimum_required(VERSION 3.25)
project(MyMalloc C)

set(CMAKE_C_STANDARD 99)

add_executable(MyMalloc main.c allocator.c allocator.h)
