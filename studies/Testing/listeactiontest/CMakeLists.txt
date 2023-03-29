cmake_minimum_required(VERSION 3.13)
project(liste_v1 C)

set(CMAKE_C_STANDARD 99)

add_executable(liste_v1 main.c liste.h liste.c)

add_executable(test-liste test.c liste.h liste.c)