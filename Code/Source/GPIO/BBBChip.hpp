
#ifndef GPIO_BBB_GPIO_CHIP_HPP__
#define GPIO_BBB_GPIO_CHIP_HPP__

#include "GpioChip.hpp"

namespace GPIO
{

enum class BBBPins : std::uint8_t
{

};

/**
 * @brief TBW
 * @note Inherited as protected as we don't want to use
 * the original methods for writing and reading inherited from GPIOChip.
 * 
 * @author AK aka MrAviator93
 */
class CBBBGPIOChip : protected CGPIOChip
{
public:
	CBBBGPIOChip()
		: CGPIOChip( m_bbbChipName )
	{ }

	void write( BBBPins pin, PinState state )
	{
		// TODO
	}

	template < typename... Args >
	void write( BBBPins pin, PinState state, Args... args )
	{
		// TODO
	}

	template < typename... Args >
	void writeHigh( BBBPins pin, Args... args )
	{
		// TODO
	}

	template < typename... Args >
	void writeLow( BBBPins pin, Args... args )
	{
		// TODO
	}

	std::uint8_t read( BBBPins pin )
	{
		// TODO
		return 0;
	}

private:
	inline static const std::string m_bbbChipName { "TBW" }; //!< BBB has x chip(s) we can interact with
};

} // namespace GPIO
#endif // GPIO_BBB_GPIO_CHIP_HPP__
