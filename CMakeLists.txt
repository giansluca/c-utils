cmake_minimum_required(VERSION 3.25)
project(c-utils VERSION 1.0.0 LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

MESSAGE ( STATUS "current source dir: " ${CMAKE_CURRENT_SOURCE_DIR} )
MESSAGE ( STATUS "current binary dir: " ${CMAKE_CURRENT_BINARY_DIR} )

include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

# add subfolders
add_subdirectory(src)
add_subdirectory(test)

# unit tests
enable_testing()
add_test(NAME C-utils COMMAND run_test)
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")



# Example --> commands from project root
#
# Debug :
# create makefile :         cmake -S . -B build-debug -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Debug -Wno-dev
# build :                   cmake --build build-debug
# run tests :               make test -C build-debug
# build and run tests :     make all test -C build-debug
# install:                  cmake --install build-debug  
#
# Release :
# create makefile :         cmake -S . -B build-release -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release -Wno-dev
# build :                   cmake --build build-release
# run tests :               make test -C build-release
# build and run tests :     make all test -C build-release
# install:                  cmake --install build-release



