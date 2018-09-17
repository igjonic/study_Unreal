#pragma once
template<typename T>
class Queue
{
public:
	Queue(int InitCapacity=10)
	{
		Head = -1;
		Tail = -1;
		Capacity = InitCapacity;
		Data = new T[Capacity];
	}
	~Queue()
	{
		delete[] Data;
	}

	void Enqueue(T Value)
	{

		if (CurrentSize = Capacity)
		{
			return;
		}
		if (Head = -1)
		{
			Head = 0;
		}
			Tail++;
			Data[Tail%Capacity] = Value;
			CurrentSize++;
	}
	T Dequeue()
	{
		if (CurrentSize=Empty)
		{
			return -1;
		}
		T Temp = Data[Head];
		Head++;
		Head=Head% Capacity;
		CurrentSize--;
		return Temp;
	}
	bool IsFull()
	{
		if (CurrentSize == Capacity)
		{
			return true;
		}
		return false;
	}
	static T Empty;
protected:
	T *Data;
	int CurrentSize = 0;
	int Head;
	int Tail;
	int Capacity;
};

template<typename T>
T Queue<T>::Empty;