
#Add BOOSTLIB
if( DEFINED ENV{BOOSTLIB})
    # 没有找到JAVA_HOME环境变量
    message(STATUS "SET  BOOSTLIB TO LINK  " $ENV{BOOSTLIB}) 
    LINK_DIRECTORIES( $ENV{BOOSTLIB} )
else()
     message(STATUS "NO ENV{BOOSTLIB}, USER DEFAULT!" }) 
endif()


set(VARIANT_SUB_BIN_INSTALL_DIR  ${BIN_INSTALL_DIR}/Variant)

message(STATUS " ASIO BIN DIR " ${VARIANT_SUB_BIN_INSTALL_DIR}) 

add_subdirectory(example1)

