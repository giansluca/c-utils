cmake_minimum_required(VERSION 3.26)
project(c-utils VERSION 1.0.0 LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

MESSAGE ( STATUS "current source dir: " ${CMAKE_CURRENT_SOURCE_DIR} )
MESSAGE ( STATUS "current binary dir: " ${CMAKE_CURRENT_BINARY_DIR} )

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_subdirectory(src)
add_subdirectory(test)

# unit tests
enable_testing()
add_test(NAME C-utils COMMAND run-tests)
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")


# Example --> commands from project root
#
# Debug :
# create makefile :         cmake -S . -B build/debug -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Debug -Wno-dev
# build :                   cmake --build build/debug
# run tests :               make test -C build/debug (ctest --test-dir build/debug -V)
# build and run tests :     make all test -C build/debug
# install:                  cmake --install build/debug
# clean :                   cmake --build build/debug --target clean      

#
# Release :
# create makefile :         cmake -S . -B build/release -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release -Wno-dev
# build :                   cmake --build build/release
# run tests :               make test -C build/release (ctest --test-dir build/release -V)
# build and run tests :     make all test -C build/release
# install:                  cmake --install build/release
# clean :                   cmake --build build/release --target clean



