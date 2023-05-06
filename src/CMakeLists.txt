set(LIB_SOURCES
  functions/functions.c
)

set(MAIN_SOURCES
  main.c
)

set(HEADERS 
  ${CONFIG_HEADER}
  headers/functions.h
)

add_library(functions ${LIB_SOURCES} ${HEADERS})
add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main functions)

target_compile_options(main PRIVATE -m64 -Wall)
target_link_options(main PRIVATE LINKER:-lm)

# install(TARGETS functions
#   RUNTIME DESTINATION bin
#   LIBRARY DESTINATION lib
#   ARCHIVE DESTINATION lib)

# install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/functions.h DESTINATION include)

# install(TARGETS target
#         CONFIGURATIONS Debug
#         RUNTIME DESTINATION Debug/bin)
# install(TARGETS target
#         CONFIGURATIONS Release
#         RUNTIME DESTINATION Release/bin)