cmake_minimum_required(VERSION 4.0)
project(LinkedList C)

set(CMAKE_C_STANDARD 17)

add_executable(LinkedList main.c
        input.c
        input.h)
