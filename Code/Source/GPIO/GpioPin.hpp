
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
	explicit CGPIOPin( gpiod_line* pinLine, PinMode mode ) noexcept( true )
		: m_pinLine { pinLine }
		, m_pinMode { mode }
	{ }

	/// TBW
	explicit CGPIOPin( gpiod_chip* chip, std::uint32_t offset, PinMode mode ) noexcept( false );

	/// Default dtor, releases the pin line
	~CGPIOPin();

	/// TBW
	void write( PinState state );

	/// TBW
	PinState read();

	void setPinMode( PinMode mode ) noexcept( false );

private:
	gpiod_line* m_pinLine { nullptr }; //!< TBW
	PinMode m_pinMode {}; //!< TBW
};

} // namespace GPIO
#endif // GPIO_GPIO_PIN_HPP__
