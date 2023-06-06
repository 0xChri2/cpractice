cmake_minimum_required(VERSION 3.23)
project(cdrental)

set(CMAKE_CXX_STANDARD 17)

add_executable(cdrental main.cpp verleih.cpp verleih.h offer.h offer.cpp normal.h normal.cpp category.h category.cpp bestseller.h bestseller.cpp cd.cpp cd.h date.cpp date.h kunde.cpp kunde.h)
