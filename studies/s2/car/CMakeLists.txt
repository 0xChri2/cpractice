cmake_minimum_required(VERSION 3.23)
project(car)

set(CMAKE_CXX_STANDARD 17)

add_executable(car main.cpp car.cpp car.h elektriccar.h vehicle.h)
