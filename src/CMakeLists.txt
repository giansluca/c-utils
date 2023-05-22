set(MODULES_SOURCES
  modules/basic.c
  modules/struct.c
)

set(HEADERS 
  ${CONFIG_HEADER}
  modules/basic.h
  modules/struct.h
)

set(MAIN_SOURCES
  main.c
)

add_library(basic modules/basic.c modules/basic.h)
add_library(struct modules/struct.c modules/struct.h)
#add_library(modules ${MODULES_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main basic struct)

target_compile_options(main PRIVATE -m64 -Wall)
target_link_options(main PRIVATE LINKER:-lm)
