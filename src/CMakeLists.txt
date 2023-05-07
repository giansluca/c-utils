set(LIB_SOURCES
  modules/utils.c
)

set(MAIN_SOURCES
  main.c
)

set(HEADERS 
  ${CONFIG_HEADER}
  headers/utils.h
)

add_library(utils ${LIB_SOURCES} ${HEADERS})
add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main utils)

target_compile_options(main PRIVATE -m64 -Wall)
target_link_options(main PRIVATE LINKER:-lm)
