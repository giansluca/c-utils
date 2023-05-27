# build modules
add_library(basic SHARED)
target_sources(basic PRIVATE modules/basic.c)
set_target_properties(basic PROPERTIES PUBLIC_HEADER include/basic.h)
add_library(struct SHARED)
target_sources(struct PRIVATE modules/struct.c)
set_target_properties(struct PROPERTIES PUBLIC_HEADER include/struct.h)

# build executable
add_executable(c-utils)
target_sources(c-utils PRIVATE main.c)
target_link_libraries(c-utils PRIVATE basic struct)

# compiler options
target_compile_options(c-utils PRIVATE -m64 -Wall)
target_compile_options(basic PRIVATE -m64 -Wall)
target_compile_options(struct PRIVATE -m64 -Wall)

# install
install(TARGETS c-utils basic struct
    RUNTIME DESTINATION /Users/gians/Desktop/c-utils-install/bin
    LIBRARY DESTINATION /Users/gians/Desktop/c-utils-install/lib
    ARCHIVE DESTINATION /Users/gians/Desktop/c-utils-install/lib
    PUBLIC_HEADER DESTINATION /Users/gians/Desktop/c-utils-install/include)

