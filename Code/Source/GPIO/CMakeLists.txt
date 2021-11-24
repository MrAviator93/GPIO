# Defines the base filename of the library
set( GPIO_LIB_NAME_BASE gpio )

# Defines the final library name (versioned or not)
set( GPIO_COMMON_VERSION "${1.0.0}" )

# Output library name is the same than input in current releases
set( GPIO_LIB_NAME_OUTPUT ${GPIO_LIB_NAME_BASE} )

add_library( ${GPIO_LIB_NAME_OUTPUT} STATIC
    GpioChip.cpp
)
   
add_library( GPIO::${GPIO_LIB_NAME_BASE} ALIAS ${GPIO_LIB_NAME_OUTPUT} )

target_link_libraries( ${GPIO_LIB_NAME_OUTPUT}
    PRIVATE
    ${GPIOD_LIBRARY}
    fmt::fmt
)

target_include_directories( ${GPIO_LIB_NAME_OUTPUT}
    PUBLIC
    ${LIBUSB_INCLUDE_DIRS}
    $<INSTALL_INTERFACE:include/GPIO>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Source/GPIO>
    # /usr/include
)

target_compile_features( ${GPIO_LIB_NAME_OUTPUT} PUBLIC cxx_std_17 )

if( GPIO_RELEASE_VERSION )
   target_compile_definitions( ${GPIO_LIB_NAME_OUTPUT} PUBLIC -DGPIO_RELEASE_VERSION )
endif()
