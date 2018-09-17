#pragma once
#include<memory>
template<typename T>
class MyVector
{
public:
	MyVector<T>()
	{
		Size = 0;
		Capacity = 10;
		Value = new int [Capacity];
	}
	~MyVector<T>()
	{
		delete[] Value;
	}
	
	void PushBack(T NewValue);
	int GetSize();
	void Find();
	void Remove();
	T GetValue(int GetIndex);
protected:
	int Size;
	int Capacity;
	T* Value;
};

template<typename T>
inline void MyVector<T>::PushBack(T NewValue)
{
	if (Capacity <= Size)//������� ���� ũ��
	{
		Capacity = Capacity * 2;
		T* Temp = new T[Capacity];
		//memcpy(Temp, Value, sizeof(T)*Size);
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
	else//���� �ڷ� �ڿ��� �߰�
	{
		Value[Size] = NewValue;
		Size++;
	}
}