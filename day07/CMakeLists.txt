cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

project(day07 LANGUAGES C CXX)

add_executable(theCPP day07.cpp)
add_executable(theC main.c)
