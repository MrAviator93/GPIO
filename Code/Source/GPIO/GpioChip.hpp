
#ifndef GPIO_GPIO_CHIP_HPP__
#define GPIO_GPIO_CHIP_HPP__

// GPIO
#include "GpioPin.hpp"

// C++
#include <map>
#include <vector>
#include <utility>

namespace GPIO
{

/// Returns a vector of all available gpio chips
std::vector< ChipInfo > getAvailableChips();

/**
 * @class CGPIOChip
 * @brief TBW
 * 
 * @author AK aka MrAviator93
 */
class CGPIOChip
{
public:
	/**
	 * @brief Opens a gpio chip object. If fails to open, throws a GPIOException exception!
	 * @param chipName GPIO chip name as represented in the kernel
	 */
	explicit CGPIOChip( const std::string& chipName ) noexcept( false );

	/// Default dtor, closes the gpio chip.
	virtual ~CGPIOChip();

	/// A const accessor to the chip name. GPIO chip name as represented in the kernel.
	auto& getChipName() const
	{
		return m_chipName;
	}

	/// TBW
	void setPinMode( std::uint8_t pinNo, PinMode mode ) noexcept( false );

	// TBW
	template < typename... Args >
	void setPinMode( std::uint8_t pinNo, PinMode mode, Args... args ) noexcept( false )
	{
		// TODO
	}

	/// TBW
	template < typename... Args >
	void setPinAsOutput( std::uint8_t pinNo, Args... args )
	{
		// TODO Use set pin mode bulk
	}

	template < typename... Args >
	void setPinAsInput( std::uint8_t pinNo, Args... args )
	{
		// TODO Use set pin mode bulk
	}

	/// TBW
	void write( std::uint8_t pinNo, PinState state );

	/// TBW, TODO consider hardware simulated PMW signal generation
	// void writePMW( stD::uint8_t pinNo );

	template < typename... Args >
	void write( std::uint8_t pin, PinState state, Args... args )
	{
		// Pack all the variables into the command
		// and send them out in one go using libgpiod
		// Use the bulk write or something look up google !
	}

	template < typename... Args >
	void writeHigh( std::uint8_t pin, Args... args )
	{
		// put it into the bulk and write all at once!
		// using fold expression !
	}

	template < typename... Args >
	void writeLow( std::uint8_t pin, Args... args )
	{
		// TODO
	}

	/// TBW
	std::uint8_t read( std::uint8_t pinNo );

	/// TBW
	template < typename... Args >
	std::vector< std::uint8_t > readMulti( std::uint8_t pinNo, Args... args )
	{
		// TODO: Make multi write/read of pins, using the libgpiod library calls!
		return {};
	}

private:
	// TODO

private:
	// This class is non-copyable and non-movable
	CGPIOChip( const CGPIOChip& ) = delete;
	CGPIOChip( CGPIOChip&& ) = delete;
	CGPIOChip operator=( const CGPIOChip& ) = delete;
	CGPIOChip operator=( CGPIOChip&& ) = delete;

private:
	const std::string m_chipName; //!< GPIO chip name as represented in the kernel.
	gpiod_chip* m_chip { nullptr }; //!< Represents the physical GPIO chip
	std::map< std::uint8_t, CGPIOPin > m_configuredPins; //!< TBW
};

} // namespace GPIO
#endif // GPIO_GPIO_CHIP_HPP__
