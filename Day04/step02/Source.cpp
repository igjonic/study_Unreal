#include <iostream>
#include <string>
#include "Apple.h"

using namespace kim;
int main()
{
	//c malloc
	//c++ new
	int size = 5;
	Apple* a=new Apple[size];//사과 생성 
	for (int i = 0; i < 10; i++)
	{
		a[i].Weight = rand() % 10;
		a[i].quality = 1;
		a[i].Calculate();
		std::cout <<a[i].Getprice()<<std::endl;
	}
	//c free
	//c++ delete
	delete[] a;
	Apple* b = new Apple();
	delete b;
}