// Review_Step01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List<int> TestNode;
	TestNode.Push_Front(1);
	TestNode.Push_Front(2);
	TestNode.Push_Front(3);
	TestNode.Push_Front(4);
	TestNode.Push_Front(5);
	
	//Node<int>* Current=TestNode.GetHead();
	//Current = Current->Next;
	//for (Current; Current != TestNode.GetTail(); Current = Current->Next)
	//{
	//	cout << Current->Data << endl;
	//}
	
}
