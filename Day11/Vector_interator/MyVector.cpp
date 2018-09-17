#include "MyVector.h"
#include<memory>
template<typename T>
int MyVector<T>::GetSize()
{
	return Size;
}
template<typename T>
void MyVector<T>::Find()
{
}
template<typename T>
void MyVector<T>::Remove()
{
}
template<typename T>
T MyVector<T>::GetValue(int GetIndex)
{
	if (Size > GetIndex)
	{
		return Value[GetIndex];
	}
	return -1;
}
