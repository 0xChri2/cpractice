cmake_minimum_required(VERSION 3.23)
project(cdshop)

set(CMAKE_CXX_STANDARD 17)

add_executable(cdshop main.cpp category.cpp category.h normal.cpp normal.h bestseller.cpp bestseller.h offer.cpp offer.h)
