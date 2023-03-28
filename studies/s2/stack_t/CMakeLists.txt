cmake_minimum_required(VERSION 3.24)
project(stack_t C)

set(CMAKE_C_STANDARD 11)

add_executable(stack_t main.c stack.h cmake-build-debug/stack.c)
