add_library(pointers STATIC)
target_sources(pointers PRIVATE pointers.c)
set_target_properties(pointers PROPERTIES PUBLIC_HEADER pointers.h)

install(TARGETS pointers
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)