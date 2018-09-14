#pragma once
#include "List.h"

template<typename T>
class ListStack
{
public:
	ListStack<T>();
	~ListStack<T>();


	void Push(T Value);
	T Pop();

	bool IsEmpty();
	int GetSize();


protected:
	List<T> Data;
};

template<typename T>
ListStack<T>::ListStack()
{
}

template<typename T>
ListStack<T>::~ListStack()
{
}

template<typename T>
inline void ListStack<T>::Push(T Value)
{
	Data.PushBack(Value);
}

template<typename T>
inline T ListStack<T>::Pop()
{
	T Temp = *(Data.rbegin());

	Data.Remove(Data.rbegin());

	return Temp;
}

template<typename T>
inline bool ListStack<T>::IsEmpty()
{
	return (Data.GetSize() == 0);
}

template<typename T>
inline int ListStack<T>::GetSize()
{
	return Data.GetSize();
}
