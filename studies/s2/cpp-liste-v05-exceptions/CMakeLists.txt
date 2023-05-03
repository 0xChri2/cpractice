cmake_minimum_required(VERSION 3.13)
project(cpp_liste)

set(CMAKE_CXX_STANDARD 17)

add_executable(liste main.cpp exception.h exception.cpp liste.h liste.cpp)
