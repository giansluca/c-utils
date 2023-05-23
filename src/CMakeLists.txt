set(MODULES_SOURCES
  modules/basic.c
  modules/struct.c
)

set(MAIN_SOURCES
  main.c
)

# build executable
add_library(modules STATIC ${MODULES_SOURCES})
set_target_properties(modules PROPERTIES PUBLIC_HEADER "include/basic.h, include/struct.h")
add_executable(c-utils ${MAIN_SOURCES})
target_link_libraries(c-utils modules)

# to export modules as libs
add_library(basic STATIC modules/basic.c)
add_library(struct STATIC modules/struct.c)
set_target_properties(basic PROPERTIES PUBLIC_HEADER "include/basic.h")
set_target_properties(struct PROPERTIES PUBLIC_HEADER "include/struct.h")

# compiler options
target_compile_options(c-utils PRIVATE -m64 -Wall)
target_link_options(c-utils PRIVATE LINKER:-lm)

# install
install(TARGETS c-utils
    RUNTIME DESTINATION /Users/gians/Desktop/c-utils-install)

install(TARGETS basic struct
    ARCHIVE DESTINATION /Users/gians/Desktop/c-utils-install/lib
    PUBLIC_HEADER DESTINATION /Users/gians/Desktop/c-utils-install/include)

