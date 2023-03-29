cmake_minimum_required(VERSION 3.23)
project(stack_t C)

set(CMAKE_C_STANDARD 11)

add_executable(stack_t main.c stack.c)
