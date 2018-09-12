#pragma once
#include<memory>
template<typename T>
class MyVectorT
{
public:
	MyVectorT()
	{
		Capacity = 10;
		Size = 0;
		Value = new T[Capacity];
	};
	~MyVectorT()
	{
		delete[] Value;
	};
	void PushBack(T NewValue);
	T& GetValue(int GetIndex);
	int GetSize();
	void Erase(int Index);
	int Find(T SerchValue);
	static T Empty;

	T& operator[](int Index)
	{
		return GetValue(Index);
	}
protected:
	int Size;
	T* Value;
	int Capacity;
};

template<typename T>
inline void MyVectorT<T>::PushBack(T NewValue)
{
	if (Capacity <= Size)//저장공간 보다 크면
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
	else//현재 자료 뒤에만 추가
	{
		Value[Size] = NewValue;
		Size++;
	}
}

template<typename T>
inline T& MyVectorT<T>::GetValue(int GetIndex)
{
	if (Size > GetIndex)
	{
		return Value[GetIndex];
	}
	return Empty;
}

template<typename T>
inline int MyVectorT<T>::GetSize()
{
	return 0;
}

template<typename T>
inline void MyVectorT<T>::Erase(int Index)
{
	if (Index < 0 || Index > Size)
	{
		return;
	}
	else
	{
		memcpy(&Value[Index], &Value[Index + 1], sizeof(T)*(Size - Index - 1));
		Size--;
	}
}

template<typename T>
inline int MyVectorT<T>::Find(T SerchValue)
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
template<typename T>
T MyVectorT<T>::Empty;