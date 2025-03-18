cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_STANDARD 14)
set(CMAKE_CXX_STANDARD 14)

project(day07 LANGUAGES C CXX)

add_executable(day07 day07.cpp)
