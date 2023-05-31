cmake_minimum_required(VERSION 3.23)
project(Bank)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bank main.cpp account.cpp account.h date.cpp date.h Girokonto.cpp Girokonto.h)
