
set( REQUIRED_LIBS 
    GPIO::gpio
    ${GPIOD_LIBRARY}
    fmt::fmt
    pthread
)

set( EXECUTABLE_OUT_NAME_1 enumerate_gpio_chips )

add_executable( ${EXECUTABLE_OUT_NAME_1} 
    MainEnumaratingChips.cpp
)

target_link_libraries( ${EXECUTABLE_OUT_NAME_1}
    ${REQUIRED_LIBS}
)

if ( UNIX )
    set_target_properties( ${EXECUTABLE_OUT_NAME_1} PROPERTIES LINK_FLAGS "-no-pie" )
endif()
