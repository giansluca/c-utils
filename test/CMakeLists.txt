find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

# build executable
add_executable(run-tests)
target_sources(run-tests PRIVATE 
  test_runner.c
  modules/utils.h
  modules/utils.c
  modules/test_basic.c
  modules/test_structs.c
  modules/test_arrays.c
  modules/test_pointers.c
  modules/test_malloc.c
)
target_link_libraries(run-tests basic structs arrays pointers malloc ${CHECK_LIBRARIES})

# compiler options
target_compile_options(run-tests PRIVATE -m64 -Wall)