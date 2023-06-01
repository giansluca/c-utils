add_library(arrays STATIC)
target_sources(arrays PRIVATE arrays.c)
set_target_properties(arrays PROPERTIES PUBLIC_HEADER arrays.h)
target_compile_options(arrays PRIVATE -m64 -Wall)

install(TARGETS arrays
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)