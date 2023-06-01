add_library(structs STATIC)
target_sources(structs PRIVATE structs.c)
set_target_properties(structs PROPERTIES PUBLIC_HEADER structs.h)
target_compile_options(structs PRIVATE -m64 -Wall)

install(TARGETS structs
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)