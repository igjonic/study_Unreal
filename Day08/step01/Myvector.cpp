#include "Myvector.h"
#include<iostream>
#include<memory.h>

MyVector::MyVector()
{
	Size = 0;
	Capacity = 10;
	Value = new int[Capacity];
	//AssignAddStorage();
}


MyVector::~MyVector()
{
		delete[] Value;
}

void MyVector::PushBack(int NewValue)
{

	if (Capacity <= Size)//저장공간 보다 크면
	{
		Capacity = Capacity * 2;
		int* Temp = new int[Capacity];
		for (int i = 0; i < Size; ++i)
		{
			Temp[i] = Value[i];
		}
		Temp[Size] = NewValue;
		delete[] Value;
		Value = Temp;
		Size++;
		std::cout << "Allocation" << std::endl;
	}
	else//현재 자료 뒤에만 추가
	{
		Value[Size] = NewValue;
		Size++;
	}
}

int MyVector::GetValue(int GetIndex)
{
	if (Size > GetIndex)
	{
		return Value[GetIndex];
	}
	return -1;
}

int MyVector::GetSize()
{
	return Size;
}

void MyVector::Erase(int Index)
{
	//for (int i = Index; i < Size-1; ++i)
	//{
	//	Value[i] = Value[i + 1];
	//}
	if (Index>0 || Index>Size)
	{
		memcpy(&Value[Index], &Value[Index + 1], sizeof(int)*(Size - Index - 1));
		Size--;
	}
}

int MyVector::Find(int SerchValue)
{
	for (int i = 0; i < Size; ++i)
	{
		if (Value[i] == SerchValue)
		{
			return i;
		}
	}
	return -1;
}


