
#Add BOOSTLIB
if( DEFINED ENV{BOOSTLIB})
    # 没有找到JAVA_HOME环境变量
    message(STATUS "SET  BOOSTLIB TO LINK  " $ENV{BOOSTLIB}) 
    LINK_DIRECTORIES( $ENV{BOOSTLIB} )
else()
     message(STATUS "NO ENV{BOOSTLIB}, USER DEFAULT!" }) 
endif()


set(BEAST_SUB_BIN_INSTALL_DIR  ${BIN_INSTALL_DIR}/Beast)

message(STATUS " ASIO BIN DIR " ${ASIO_SUB_BIN_INSTALL_DIR}) 



add_subdirectory(example2)
