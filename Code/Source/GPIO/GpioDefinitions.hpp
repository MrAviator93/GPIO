
#ifndef GPIO_GPIO_DEFINITIONS_HPP__
#define GPIO_GPIO_DEFINITIONS_HPP__

// C++
#include <string>

struct gpiod_chip;
struct gpiod_line;

// General Purpose Input Output library
namespace GPIO
{

struct GPIOException : public std::exception
{
	explicit GPIOException( const std::string& what )
		: m_what { "GPIO " + what }
	{ }

	const char* what() const noexcept( true ) override
	{
		return m_what.c_str();
	}

private:
	std::string m_what {}; //!< An exception message
};

/// TBW
struct ChipInfo
{
	std::string chip {}; //!< GPIO chip name as represented in the kernel.
	std::string chip_label {}; //!< GPIO chip label as represented in the kernel.
	std::uint32_t num_lines {}; //!< The number of GPIO lines exposed by this chip.
	// gpiod_chip* chip { nullptr }; //!< A pointer, that points to libgpiod chip object.
};

enum class PinMode : std::uint8_t
{
	OUTPUT = 0,
	INPUT = 1
};

enum class PinState : std::uint8_t
{
	LOW = 0,
	HIGH = 1
};

} // namespace GPIO
#endif // GPIO_GPIO_DEFINITIONS_HPP__
