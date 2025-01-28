cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

project(day01 LANGUAGES C CXX)

add_executable(day01 day01.c)

configure_file(day01.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
