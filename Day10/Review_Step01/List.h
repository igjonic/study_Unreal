#pragma once
template<typename T>
class Node
{
public:
	T Data;
	Node<T>* Next;
	Node<T>* Prev;
};
template<typename T>
class Iterator
{
public:

	Iterator(Node<T>* init = nullptr) { Current = init; }
	Iterator& operator++()
	{
		Current = Current->Next;
		return *this;
	}
	bool operator!=(const Iterator& rhs)
	{
		return (Current != rhs.Current);
	}

	T& operator*()
	{
		return Current->Data;
	}
protected:
	Node<T>* Current;
};

template<typename T>
class List
{
public:
	List();
	~List();

	void Push_Back(T Value);
	void Push_Front(T Value);
	void Push_InsertBefore(Node<T>* InsertNode, T Value);
	void Push_InsertAfter(Node<T>* InsertNode, T Value);
	Node<T>* Find(T Value);
	Node<T>* Remove(Node<T>* DeleteNode);
	void RemoveAll();
	void GetSize();
	Node<T>* GetHead()
	{
		return Head;
	}
	Node<T>* GetTail()
	{
		return Tail;
	}

protected:
	Node<T>* Head;
	Node<T>* Tail;
	int Size;
};

