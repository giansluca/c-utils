find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

# build executable
add_executable(run_test)
target_sources(run_test PRIVATE 
  test_runner.c
  modules/test_basic.c
  include/test_basic.h
  modules/test_struct.c
  include/test_struct.h
)
target_link_libraries(run_test basic struct ${CHECK_LIBRARIES})

# compiler options
target_compile_options(run_test PRIVATE -m64 -Wall)