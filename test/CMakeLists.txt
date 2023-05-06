# If pkg-config is not installed on the system, then the CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/functions
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/headers)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
  test_runner.c
  functions/test_functions.c
)

add_executable(test_all ${TEST_SOURCES})
target_link_libraries(test_all functions ${CHECK_LIBRARIES})

target_compile_options(test_all PRIVATE -m64 -Wall)
target_link_options(test_all PRIVATE LINKER:-lm)