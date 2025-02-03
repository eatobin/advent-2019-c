cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

project(day05 LANGUAGES C CXX)

add_executable(day05 day05.c)
