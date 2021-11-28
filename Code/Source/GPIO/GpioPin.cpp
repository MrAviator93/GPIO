
#include "GpioPin.hpp"

// 3rd Party
#include <gpiod.hpp>
#include <fmt/format.h>

namespace GPIO
{

CGPIOPin::CGPIOPin( gpiod_chip* chip, std::uint32_t offset, PinMode mode ) noexcept( false )
	: m_pinMode { mode }
{
	m_pinLine = gpiod_chip_get_line( chip, offset );
	if( !m_pinLine )
	{
		throw GPIOException { "Failed to retrieve the GPIO pin at offset: " + std::to_string( offset ) };
	}

	int rslt {};
	if( mode == PinMode::OUTPUT )
	{
		rslt = gpiod_line_request_output( m_pinLine, "gpiocd", 0 );
	}

	if( mode == PinMode::INPUT )
	{
		rslt = gpiod_line_request_input( m_pinLine, "gpiocd" );
	}

	if( rslt < 0 )
	{
		throw GPIOException( fmt::format( "Unable to configure pinline at offset: ( {} )", offset ) );
	}
}

CGPIOPin::~CGPIOPin()
{
	if( m_pinLine )
	{
		gpiod_line_release( m_pinLine );
	}
}

void CGPIOPin::write( PinState state )
{
	// TODO
}

PinState CGPIOPin::read()
{
	// TODO
	return {};
}

void CGPIOPin::setPinMode( PinMode mode ) noexcept( false )
{
	int rslt {};
	if( mode == PinMode::OUTPUT )
	{
		rslt = gpiod_line_request_output( m_pinLine, "gpiocd", 0 );
	}

	if( mode == PinMode::INPUT )
	{
		rslt = gpiod_line_request_input( m_pinLine, "gpiocd" );
	}

	if( rslt < 0 )
	{
		throw GPIOException( fmt::format( "Unable to configure pin at offset: ( {} )", 0 /* m_pinLine-> */ ) );
	}
}

} // namespace GPIO
