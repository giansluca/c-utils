# If pkg-config is not installed on the system, then the CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/modules
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/headers)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
  test_runner.c
  modules/test_utils.c
)

add_executable(target_test ${TEST_SOURCES})
target_link_libraries(target_test utils ${CHECK_LIBRARIES})

target_compile_options(target_test PRIVATE -m64 -Wall)
target_link_options(target_test PRIVATE LINKER:-lm)