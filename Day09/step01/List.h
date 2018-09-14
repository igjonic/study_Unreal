#pragma once

class Node
{
public:
	int Data;
	Node* Next;
	Node* Pre;

	//Node& operator++()
	//{
	//	return *Next;
	//}
};

class List
{
public:
	List();
	~List();
	void Insert(T Value);
	void PushBack(T Value);
	Node* Begin()
	{
		return Head->Next;
	}

	Node* End()
	{
		return Tail;
	}


	void PushFront(int Value);
	Node* Remove(Node* DeleteNode);
	void IsertBefore(Node* Point, int Value);
	void IsertAfter(Node* Point, int Value);
	void RemoveAll();
	 Node* GetHead();
	 Node* GetTail();
	 Node* Find(int Value);
	 Node* RFind(int Value);
protected:
	Node* Head;
	Node* Tail;
	int Size;
};

