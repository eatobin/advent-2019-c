cmake_minimum_required(VERSION 3.29)
project(day01 C)

set(CMAKE_C_STANDARD 11)

add_executable(day01 day01.c)

configure_file(day01.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
