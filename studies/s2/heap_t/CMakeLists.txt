cmake_minimum_required(VERSION 3.23)
project(heap_t C)

set(CMAKE_C_STANDARD 99)

add_executable(heap_t main.c heap.h heap.c)
