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
# Check headers
set(INCLUDES "")
macro(ck_check_include_file header var)
  check_include_files("${INCLUDES};${header}" ${var})
  if(${var})
    set(INCLUDES ${INCLUDES} ${header})
  endif(${var})
endmacro(ck_check_include_file)

ck_check_include_file("stdlib.h" HAVE_STDLIB_H)

###############################################################################
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

###############################################################################
# Subdirectories
add_subdirectory(src)
add_subdirectory(test)

###############################################################################
# Unit tests
enable_testing()
add_test(NAME C-utils COMMAND target_test)
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")


# run tests in :          make test
# run tests out :         make test -C build-debug
# build and run tests :   make all test
