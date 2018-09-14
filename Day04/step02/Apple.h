#pragma once
#include <string>
namespace kim
{
	class Apple
	{
	public:
		std::string Color;
		float Weight;
		std::string taste;
		float quality;
		int calorie;

		void EatBy();
		void Calculate();
		inline int Getprice() { return price; }
	private:
		int price;
	};
}