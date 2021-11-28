
// GPIO
#include <GpioChip.hpp>

// C++
#include <iostream>

int main( int, char** )
{
	auto chips = GPIO::getAvailableChips();

	std::cerr << "Available chips: " << chips.size() << std::endl;

	for( const auto& chip : chips )
	{
		std::cerr << chip.chip_label << std::endl;
	}

	return 0;
}
