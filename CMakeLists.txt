cmake_minimum_required(VERSION 3.25)
project(c-utils VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(SOURCE_FILES
        main.c
        functions/functions.c)

add_executable(c-utils ${SOURCE_FILES})

target_compile_options(c-utils PRIVATE -m64 -Wall)

target_link_options(c-utils PRIVATE LINKER:-lm)