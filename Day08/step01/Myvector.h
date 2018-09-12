#pragma once
class MyVector
{
public:
	MyVector();
	~MyVector();
	void PushBack(int NewValue);

	int GetValue(int GetIndex);
	int GetSize();	
	void Erase(int Index);
	int Find(int SerchValue);

protected:
	int Size;
	int* Value;
	int Capacity;
};

