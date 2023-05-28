# build modules
add_library(basic STATIC)
target_sources(basic PRIVATE modules/basic.c)
set_target_properties(basic PROPERTIES PUBLIC_HEADER modules/basic.h)
add_library(structs STATIC)
target_sources(structs PRIVATE modules/structs.c)
set_target_properties(structs PROPERTIES PUBLIC_HEADER modules/structs.h)
add_library(arrays STATIC)
target_sources(arrays PRIVATE modules/arrays.c)
set_target_properties(arrays PROPERTIES PUBLIC_HEADER modules/arrays.h)

# build executable
add_executable(c-utils)
target_sources(c-utils PRIVATE main.c)
target_link_libraries(c-utils PRIVATE basic structs arrays)

# compiler options
target_compile_options(c-utils PRIVATE -m64 -Wall)
target_compile_options(basic PRIVATE -m64 -Wall)
target_compile_options(structs PRIVATE -m64 -Wall)
target_compile_options(arrays PRIVATE -m64 -Wall)

# install
install(TARGETS c-utils basic structs arrays
    RUNTIME DESTINATION /Users/gians/Desktop/c-utils-install/bin
    LIBRARY DESTINATION /Users/gians/Desktop/c-utils-install/lib
    ARCHIVE DESTINATION /Users/gians/Desktop/c-utils-install/lib
    PUBLIC_HEADER DESTINATION /Users/gians/Desktop/c-utils-install/include)

