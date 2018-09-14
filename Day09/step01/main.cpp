#include<iostream>
#include"List.h"

using namespace std;

int main()
{
	List TestList;
	
	//TestList.Insert(1);
	//TestList.Insert(2);
	//TestList.Insert(3);

	//Node* Current = TestList.GetHead();
	//while (Current)
	//{
	//	Current = Current->Next;
	//	cout <<"현재 데이타"<< Current->Data << endl;
	//	
	//}
	//TestList.PushBack(1);
	//TestList.PushBack(2);
	//TestList.PushBack(3);

	TestList.PushFront(1);
	TestList.PushFront(2);
	TestList.PushFront(3);
	for (Node* Cusor = TestList.Begin(); Cusor != TestList.End(); Cusor=Cusor->Next)
	{
		cout << Cusor->Data << endl;
	}


	return 0;
}