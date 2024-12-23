cmake_minimum_required(VERSION 3.28)
project(c C)

set(CMAKE_C_STANDARD 23)

add_executable(
        c
        main.c
        stack/stack.c
        stack/stack.h
        queue/queue.c
        queue/queue.h
)
