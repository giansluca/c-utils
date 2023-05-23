find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
  test_runner.c
  modules/test_basic.c
  modules/test_struct.c
)

# build executable
add_executable(run_test ${TEST_SOURCES})
target_link_libraries(run_test modules ${CHECK_LIBRARIES})

# compiler options
target_compile_options(run_test PRIVATE -m64 -Wall)
target_link_options(run_test PRIVATE LINKER:-lm)