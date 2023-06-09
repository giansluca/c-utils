find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

# build executable
add_executable(run-tests)
target_sources(run-tests PRIVATE 
  test_runner.c
  utils/common.c
  utils/common.h
  modules/test_basic.c
  modules/test_structs.c
  modules/test_arrays.c
  modules/test_pointers.c
  modules/test_malloc.c
)

target_link_libraries(run-tests PRIVATE basic structs arrays pointers malloc)

if(WIN32)
  target_link_libraries(run-tests ${CHECK_LIBRARIES})
elseif(APPLE)
  target_link_libraries(run-tests ${CHECK_LIBRARIES})
elseif(UNIX)
  target_link_libraries(run-tests ${CHECK_LIBRARIES} -lm -lrt -lpthread -lsubunit)
endif()

