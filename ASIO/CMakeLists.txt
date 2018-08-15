
#Add BOOSTLIB
if( DEFINED ENV{BOOSTLIB})
    # 没有找到JAVA_HOME环境变量
    message(STATUS "SET  BOOSTLIB TO LINK  " $ENV{BOOSTLIB}) 
    LINK_DIRECTORIES( $ENV{BOOSTLIB} )
else()
     message(STATUS "NO ENV{BOOSTLIB}, USER DEFAULT!" }) 
endif()

add_subdirectory(Example1)
add_subdirectory(PostAll)