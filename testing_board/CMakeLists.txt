cmake_minimum_required(VERSION 4.2)
project(Unix_System C)

set(CMAKE_C_STANDARD 11)

add_executable(buff
        buff.c)

add_executable(buff2
        buff2.c)


add_executable(refer
        reference_null.c
)
add_executable(checkpass checkpass.c)
