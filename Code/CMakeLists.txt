cmake_minimum_required( VERSION "3.20.0" )

project( GPIOLib VERSION 1.0 LANGUAGES CXX )

option( GPIO_BUILD_TESTS "Builds the unit tests." ON )
option( GPIO_BUILD_UTILITIES "Builds utility programs." ON )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED TRUE )

# We are installing GPIO libs inside /usr/local/ak directory (for future)
set( CMAKE_INSTALL_PREFIX "/usr/local/ak") 

find_library( GPIOD_LIBRARY NAMES libgpiod.so )
if( NOT GPIOD_LIBRARY )
        message( FATAL_ERROR "gpiod library has not been found. Install apt install libgpiod-dev" )
endif()

find_package( fmt CONFIG REQUIRED )

add_subdirectory( Source )

if ( GPIO_BUILD_TESTS )
    add_subdirectory( Test )
endif()

if ( GPIO_BUILD_UTILITIES )
        add_subdirectory( Utilities )
endif()

if ( GPIO_CORE_GENERATE_DOC )
        find_package( Doxygen )
        if ( DOXYGEN_FOUND )
                set( DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/DocDoxygen/Doxyfile.in )
                set( DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile )

                configure_file( ${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY )

                add_custom_target( Docs
                        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                        COMMENT "Generating API documentation with Doxygen"
                        VERBATIM )
        else ()
                message( "Doxygen has not been found on the current system. Install it in order to generate the documentation." )
        endif ()
endif()
