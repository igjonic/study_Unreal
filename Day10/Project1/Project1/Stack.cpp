#include "Stack.h"


int Stack::Pop()
{
	if (--Size < 0)
	{
		return -1;
	}

	return Data[Size];
}

bool Stack::Push(int Value)
{
	if (Size == Capacity)
	{
		return false;
	}

	Data[Size] = Value;
	Size++;

	return true;
}
