#include "Apple.h"
#include <iostream>

namespace kim
{
	void Apple::EatBy()
	{
		std::cout << "¸ÔÇû´Ù.";
	}
	void Apple::Calculate()
	{
		price = quality * Weight;
	}
}