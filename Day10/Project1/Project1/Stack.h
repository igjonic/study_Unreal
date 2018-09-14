#pragma once
class Stack
{
public:
	Stack(int StackSize = 10)
	{
		Data = new int[StackSize];
		Capacity = StackSize;
		Size = 0;
	}

	~Stack()
	{
		delete[] Data;
	}

	int GetSize()
	{
		return Size;
	}

	bool IsEmpty()
	{
		return (Size == 0);
	}

	bool IsFull()
	{
		return (Size == Capacity);
	}

	bool Resize(int NewSize)
	{
		if (NewSize <= 0 || NewSize == Capacity)
		{
			return false;
		}

		int* NewData = new int[NewSize];
		if (NewData == nullptr)
		{
			return false;
		}

		Capacity = NewSize;
		Size = Size > NewSize ? NewSize : Size;
		for (int i = 0; i < Size; ++i)
		{
			NewData[i] = Data[i];
		}

		delete[] Data;

		Data = NewData;

		return true;
	}

	int Pop();
	bool Push(int Value);

protected:
	int* Data;
	int Capacity;
	int Size;
};