
#Add BOOSTLIB
if( DEFINED ENV{BOOSTLIB})
    # 没有找到JAVA_HOME环境变量
    message(STATUS "SET  BOOSTLIB TO LINK  " $ENV{BOOSTLIB}) 
    LINK_DIRECTORIES( $ENV{BOOSTLIB} )    
else()
     message(STATUS "SET  BOOSTLIB TO LINK  " $ENV{BOOSTLIB}) 
endif()

add_subdirectory(src)