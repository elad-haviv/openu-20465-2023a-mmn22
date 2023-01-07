cmake_minimum_required(VERSION 3.24)
project(homework-22 C)

set(CMAKE_C_STANDARD 90)

add_executable(homework-22 myset.c parse.c set.c input.c execute.c set_helpers.c)