# build executable
add_executable(c-utils)
target_sources(c-utils PRIVATE main.c)
target_link_libraries(c-utils PRIVATE basic structs arrays pointers malloc)

# compiler options
target_compile_options(c-utils PRIVATE -m64 -Wall)

# install
install(TARGETS c-utils
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)

add_subdirectory(basic)
add_subdirectory(structs)
add_subdirectory(arrays)
add_subdirectory(pointers)
add_subdirectory(malloc)

