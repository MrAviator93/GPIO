
#ifndef GPIO_RPI4_GPIO_CHIP_HPP__
#define GPIO_RPI4_GPIO_CHIP_HPP__

#include "GpioChip.hpp"

namespace GPIO
{

enum class RPI4Pins : std::uint8_t
{

};

/**
 * @brief TBW
 * @note Inherited as protected as we don't want to use
 * the original methods for writing and reading inherited from GPIOChip.
 * 
 * @author AK aka MrAviator93
 */
class CRPI4GPIOChip : protected CGPIOChip
{
public:
	CRPI4GPIOChip();

	void write( RPI4Pins pin, PinState state )
	{
		// TODO
	}

	template < typename... Args >
	void write( RPI4Pins pin, PinState state, Args... args )
	{
		// TODO
	}

	template < typename... Args >
	void writeHigh( RPI4Pins pin, Args... args )
	{
		// TODO
	}

	template < typename... Args >
	void writeLow( RPI4Pins pin, Args... args )
	{
		// TODO
	}

	std::uint8_t read( RPI4Pins pin )
	{
		// TODO
		return 0;
	}

private:
	inline static const std::string m_rpi4ChipName { "gpiochip0" }; //!< RPI4 has only one chip we can interact with
};

} // namespace GPIO
#endif // GPIO_RPI4_GPIO_CHIP_HPP__
