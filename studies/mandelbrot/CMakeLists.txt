cmake_minimum_required(VERSION 3.8)
project(Mandelbrot C)
set(CMAKE_C_STANDARD 99)

add_executable(Mandelbrot main.c)

target_link_libraries(Mandelbrot PRIVATE m)
