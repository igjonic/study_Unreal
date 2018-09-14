#include "List.h"

List::List()
{
	
	Head = new Node();
	Tail = new Node();
	Head->Next = Tail;
	Tail->Pre = Head;
	Size = 0;
}


List::~List()
{

	RemoveAll();
	delete Head;
	delete Tail;

}

void List::Insert(int Value)
{
	if (Head->Next == Tail)
		{
			Node* NewNode = new Node();
			NewNode->Data = Value;
			NewNode->Next = Tail;
			NewNode->Pre = Head;
			Head->Next = NewNode;
			Size++;
		}
		else
		{
			Node* NewNode = new Node();
			NewNode->Data = Value;
			NewNode->Next = Tail;
			Head->Next = NewNode;

			Node* CurrentNode = Head->Next;
			while (CurrentNode->Next!=Tail)
			{
				CurrentNode->Pre = CurrentNode;
				CurrentNode = CurrentNode->Next;
			}
			CurrentNode->Next = NewNode;
			Size++;
		}
}

void List::PushBack(int Value)
{
	IsertBefore(Tail, Value);
}

void List::PushFront(int Value)
{
	IsertAfter(Head, Value);
}

Node* List::Remove(Node* DeleteNode)
{

	//if (Index == 0)
	//{
	//	//Head 삭제
	//	Node* NewHead = Head;
	//	NewHead = Head->Next;
	//	delete Head;
	//	Head = NewHead;
	//	Size--;
	//}
	//else
	//{
	//	Node* RemoverPrev=Head;
	//	for (int i = 0; i < Index - 1; ++i)
	//	{
	//		RemoverPrev = RemoverPrev->Next;
	//	}
	//	Node* RemoveNode = RemoverPrev->Next;
	//	Node* RemoveNext = RemoveNode->Next;
	//	RemoverPrev->Next = RemoveNext;
	//	delete RemoveNode;
	//	Size--;
	//}
	if (DeleteNode == Head ||
		DeleteNode == Tail ||
		DeleteNode == nullptr)
	{
		return nullptr;
	}
	DeleteNode->Pre->Next = DeleteNode->Next;
	DeleteNode->Next->Pre = DeleteNode->Pre;
	Node* NextNode = DeleteNode->Pre;
	delete DeleteNode;
	Size;
	return NextNode;
}

void List::IsertBefore(Node * Point, int Value)
{
	if (Point == nullptr || Point == Head)
	{
		return;
	}
	else
	{
		Node* NewNode = new Node();
		NewNode->Data = Value;

		Node* OldPrevNode = Point->Pre;
		Point->Pre = NewNode;
		NewNode->Pre = OldPrevNode;
		OldPrevNode->Next = NewNode;
		NewNode->Next = Point;
		Size++;
	}
}

void List::IsertAfter(Node * Point, int Value)
{
	if (Point == nullptr || Point == Tail)
	{
		return;
	}
	else
	{
		Node* NewNode = new Node();
		NewNode->Data = Value;

		Node* OldNextNode = Point->Next;
		Point->Next = NewNode;
		NewNode->Next = OldNextNode;
		OldNextNode->Pre = NewNode;
		NewNode->Pre = Point;
		Size++;
	}
}

void List::RemoveAll()
{
	Node* FindNode = Head;
	for (Node*Cusor = Begin(); Cusor != End(); Cusor = Cusor->Next)
	{
		Cusor = Remove(Cusor);//Remove 할때 정방향만
	}
	Size = 0;
}

 Node * List::GetHead()
{
	return Head;
}

 Node * List::GetTail()
 {
	 return Tail;
 }

 Node * List::Find(int Value)
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

 Node * List::RFind(int Value)
 {
	 Node* FindNode = Tail;
	 for (int i = Size; i= 0; --i)
	 {
		 if (FindNode->Data = Value)
		 {
			 return FindNode;
		 }
		 FindNode = FindNode->Pre;
	 }
	 return nullptr;
 }
