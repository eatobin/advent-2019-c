cmake_minimum_required(VERSION 3.30)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

project(day02 LANGUAGES C CXX)

add_executable(day02
        file_fns.c
        main.c)

configure_file(day02.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(test-file.csv
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
