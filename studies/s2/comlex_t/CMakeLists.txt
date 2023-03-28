cmake_minimum_required(VERSION 3.24)
project(comlex_t C)

set(CMAKE_C_STANDARD 11)

add_executable(comlex_t main.c complex.h complex.c)
