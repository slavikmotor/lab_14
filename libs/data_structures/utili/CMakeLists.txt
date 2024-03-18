cmake_minimum_required(VERSION 3.26)
project(lab_14 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_14 main.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.c
        main.c
        libs/utili/utili.h
        libs/utili/utili.c)
