#pragma once
#include "List.h"
template<typename T>
class ListStack2 : public List<T>
{
public:
	ListStack2();
	~ListStack2();

	void Push(T Value);
	T Pop();


	bool IsEmpty()
	{
		return (List<T>::Size == 0);
	}
protected:
	void RemoveNode(Node<T>* Where); //Stack��
};

template<typename T>
ListStack2<T>::ListStack2()
{
}

template<typename T>
ListStack2<T>::~ListStack2()
{
}

template<typename T>
void ListStack2<T>::Push(T Value)
{
	List<T>::PushBack(Value);
}

template<typename T>
inline T ListStack2<T>::Pop()
{
	T temp = List<T>::Tail->Prev->Data;

	RemoveNode(List<T>::Tail->Prev);

	return temp;
}


template<typename T>
inline void ListStack2<T>::RemoveNode(Node<T>* Where)
{
	if (Where == List<T>::Head)
	{
		return;
	}

	Where->Prev->Next = Where->Next; //����°� ������ ����°� �����ɷ� ����
	Where->Next->Prev = Where->Prev; //����°� �������� ���� ����°� ����

	delete Where;

	List<T>::Size--;
}

