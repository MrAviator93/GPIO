
#include "GpioChip.hpp"

// 3rd Party
#include <gpiod.hpp>
#include <fmt/format.h>

namespace GPIO
{
std::vector< ChipInfo > getAvailableChips()
{
	std::vector< ChipInfo > iffos;

	auto it = gpiod_chip_iter_new();
	if( !it )
	{
		// Not a single gpio chip is available
		return iffos;
	}

	gpiod_chip* chip { nullptr };
	gpiod_foreach_chip( it, chip )
	{
		ChipInfo ci { gpiod_chip_name( chip ), gpiod_chip_label( chip ), gpiod_chip_num_lines( chip ) };
		iffos.push_back( ci );
	}
	gpiod_chip_iter_free( it );
	return iffos;
}

CGPIOChip::CGPIOChip( const std::string& chipName ) noexcept( false )
	: m_chipName { chipName }
{
	m_chip = gpiod_chip_open_by_name( chipName.c_str() );
	if( !m_chip )
	{
		throw GPIOException( fmt::format( "The {} chip doesn't exist.", chipName ) );
	}
}

CGPIOChip::~CGPIOChip()
{
	if( m_chip )
	{
		m_configuredPins.clear();
		gpiod_chip_close( m_chip );
	}
}

void CGPIOChip::write( std::uint8_t pinNo, PinState state )
{
	auto it = m_configuredPins.find( pinNo );
	if( it == m_configuredPins.end() )
	{
		throw GPIOException { "Unconfigured pin at offset: " + pinNo };
	}

	it->second.write( state );
}

std::uint8_t CGPIOChip::read( std::uint8_t pinNo )
{
	auto it = m_configuredPins.find( pinNo );
	if( it == m_configuredPins.end() )
	{
		throw GPIOException { "Unconfigured pin at offset: " + pinNo };
	}

	return it->second.read();
}

void CGPIOChip::setPinMode( std::uint8_t pinNo, PinMode mode ) noexcept( false )
{
	auto it = m_configuredPins.find( pinNo );
	if( it == m_configuredPins.end() )
	{
		// We simply add a new pin line to the map
		// m_configuredPins.insert( { pinNo, CGPIOPin { m_chip, mode } } );
	}
	else
	{
		// Modify the state of the already present pin line
		it->second.setPinMode( mode );
	}
}

} // namespace GPIO
