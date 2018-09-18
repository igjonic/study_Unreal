#pragma once
class Queue
{
public:
	Queue() 
	{
		Head = -1;
		Tail = -1;
		CrrentSize = 0;
		Data = new int[Capacity];
	}
	~Queue()
	{
		delete[] Data;
	}
	void Input(int Value)
	{
		if (CrrentSize == Capacity)
		{
			return;
		}
		if (Head == -1)
		{
			Head = 0;
		}
		Tail++;
		Data[Tail%Capacity] = Value;
		CrrentSize++;
	}
	int Pop()
	{
		if (CrrentSize == 0)
		{
			return -1;
		}
		int Temp = Data[Head];
		Head++;
		Head=Head%Capacity;
		return Temp;
	}

protected:
	int *Data;
	int Capacity;
	int CrrentSize;
	int Head;
	int Tail;
};

