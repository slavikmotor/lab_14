cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        libs/data_structures/vector/vector.h
        libs/data_structures/string_/string_.c
        libs/data_structures/string_/string_.h
        libs/data_structures/string_/test_string.c
)

add_subdirectory(libs)
target_link_libraries(untitled1 data_structures)





