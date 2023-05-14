cmake_minimum_required(VERSION 3.25)
project(c-utils VERSION 1.0.0 LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

###############################################################################
include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

###############################################################################
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

###############################################################################
add_subdirectory(src)
add_subdirectory(test)

###############################################################################
# Unit tests
enable_testing()
add_test(NAME C-utils COMMAND run_test)
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")

# Example --> commands from project root
#
# Debug :
# create makefile :       cmake -S . -B build-debug -D CMAKE_C_COMPILER=clang -D CMAKE_BUILD_TYPE=Debug
# build :                 cmake --build build-debug
# run tests :             make test -C build-debug
# build and run tests :   make all test -C build-debug
#
# Release :
# create makefile :       cmake -S . -B build-release -D CMAKE_C_COMPILER=clang -D CMAKE_BUILD_TYPE=Release
# build :                 cmake --build build-release
# run tests :             make test -C build-release
# build and run tests :   make all test -C build-release



