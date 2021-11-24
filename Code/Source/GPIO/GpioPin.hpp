
#ifndef GPIO_GPIO_PIN_HPP__
#define GPIO_GPIO_PIN_HPP__

// GPIO
#include "GpioDefinitions.hpp"

namespace GPIO
{

/// TBW
class CGPIOPin
{
public:
	/// Constructor for the use when we set-up/configure a bulk of pins at once
	explicit CGPIOPin( gpiod_line* pinLine, PinMode mode )
		: m_pinLine { pinLine }
		, m_pinMode { mode }
	{ }

	explicit CGPIOPin( gpiod_chip* chip, std::uint32_t offset, PinMode mode ) noexcept( false )
		: m_pinMode { mode }
	{
		// m_pinLine = gpiod_chip_get_line( chip, offset );
		// if( !m_pinLine )
		// {
		// 	throw GPIOException { "Failed to retrieve the GPIO pin at offset: " + std::to_string( offset ) };
		// }

		// int rslt {};
		// if( mode == PinMode::OUTPUT )
		// {
		// 	rslt = gpiod_line_request_output( m_pinLine, "gpiocd", 0 );
		// }

		// if( mode == PinMode::INPUT )
		// {
		// 	rslt = gpiod_line_request_input( m_pinLine, "gpiocd" );
		// }

		// if( rslt < 0 )
		// {
		// 	throw GPIOException( fmt::format( "Unable to configure pinline at offset: ( {} )", offset ) );
		// }
	}

	/// Default dtor, releases the pin line
	~CGPIOPin()
	{
		if( m_pinLine )
		{
			// gpiod_line_release( m_pinLine );
		}
	}

	void write( PinState state )
	{
		// TODO
	}

	std::uint8_t read()
	{
		// TODO
		return 0;
	}

	void setPinMode( PinMode mode )
	{
		// int rslt {};
		// if( mode == PinMode::OUTPUT )
		// {
		// 	rslt = gpiod_line_request_output( pin, "gpiocd", 0 );
		// }

		// if( mode == PinMode::INPUT )
		// {
		// 	rslt = gpiod_line_request_input( pin, "gpiocd" );
		// }

		// if( rslt < 0 )
		// {
		// 	throw GPIOException( fmt::format( "Unable to configure pin: ( {} )", pinNo ) );
		// }
	}

private:
	gpiod_line* m_pinLine { nullptr };
	PinMode m_pinMode {};
};

} // namespace GPIO
#endif // GPIO_GPIO_PIN_HPP__
