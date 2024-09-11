cmake_minimum_required(VERSION 3.29)
project(day02 C)

set(CMAKE_C_STANDARD 17)

add_executable(day02 main.c
        file_fns.c)

configure_file(day02.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(test-file.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
