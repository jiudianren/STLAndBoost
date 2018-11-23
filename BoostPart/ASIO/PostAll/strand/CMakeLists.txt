AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)
ADD_EXECUTABLE(strandTest  ${DIR_SRCS})
#TARGET_LINK_LIBRARIES(myboost boost_filesystem boost_system)
TARGET_LINK_LIBRARIES(strandTest  boost_regex boost_filesystem boost_system boost_thread pthread)

#example.cpp使用 boost-regex ，暂时没有，所以 example先不编译
#apt-get install libboost-xxx-dev
#当前ubuntu server使用的libboost1.65-dev 版本

install(TARGETS strandTest
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${ASIO_SUB_BIN_INSTALL_DIR})

