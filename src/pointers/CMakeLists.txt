add_library(pointers STATIC)
target_sources(pointers PRIVATE pointers.c)
set_target_properties(pointers PROPERTIES PUBLIC_HEADER pointers.h)
target_compile_options(pointers PRIVATE -m64 -Wall)

install(TARGETS pointers
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)