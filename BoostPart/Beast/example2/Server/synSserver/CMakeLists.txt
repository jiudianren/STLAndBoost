AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)
ADD_EXECUTABLE(syHttpSers  ${DIR_SRCS})
TARGET_LINK_LIBRARIES(syHttpSers  boost_regex boost_filesystem boost_system boost_thread  ssl crypto pthread)

install(TARGETS syHttpSers
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BEAST_SUB_BIN_INSTALL_DIR})

