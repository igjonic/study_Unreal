#include "Apple.h"
#include <iostream>

namespace kim
{
	void Apple::EatBy()
	{
		std::cout << "������.";
	}
	void Apple::Calculate()
	{
		price = quality * Weight;
	}
}