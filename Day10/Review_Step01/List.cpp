#include "List.h"

template<typename T>
List<T>::List()
{
	 Head = new Node<T>();
	 Tail = new Node<T>();
	Head->Next = Tail;
	Tail->Prev = Head;
	Size = 0;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::Push_Back(T Value)
{
	Push_InsertBefore(Tail, Value);
}
template<typename T>
void List<T>::Push_Front(T Value)
{
	Push_InsertAfter(Head, Value);
}
template<typename T>
void List<T>::Push_InsertBefore(Node<T> * InsertNode, T Value)
{
	Node<T>* NewNode = new Node<T>();
	NewNode->Data = Value;

	Node<T>* PrevNode = new Node<T>();// 앞노드 저장 노드
	PrevNode = InsertNode->Prev;
	NewNode->Next = InsertNode;
	NewNode->Prev = PrevNode;
	PrevNode->Next = NewNode;
	InsertNode->Prev = NewNode;
	Size++;
}
template<typename T>
void List<T>::Push_InsertAfter(Node<T> * InsertNode, T Value)
{
	Node<T>* NewNode = new Node<T>();
	NewNode->Data = Value;

	Node<T>* NextNode = new Node<T>();// 앞노드 저장 노드
	NextNode = InsertNode->Next;
	NewNode->Prev = InsertNode;
	NewNode->Next = NextNode;
	NextNode->Prev = NewNode;
	InsertNode->Next = NewNode;
	Size++;
}

template<typename T>
Node<T> * List<T>::Find(T Value)
{
	Node* FindNode = Head;
	for (int i = 0; i < Size; ++i)
	{
		if (FindNode->Data = Value)
		{
			return FindNode;
		}
		FindNode = FindNode->Next;
	}
	return nullptr;
}
template<typename T>
Node<T> * List<T>::Remove(Node<T> * DeleteNode)
{
	return nullptr;
}

template<typename T>
void List<T>::RemoveAll()
{
}
template<typename T>
void List<T>::GetSize()
{
}

