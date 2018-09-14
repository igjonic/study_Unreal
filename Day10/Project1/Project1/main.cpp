#include <iostream>
#include "List.h"
#include <list>
#include <string>
#include "TList.h"
#include "Stack.h"
#include "ListStack.h"
#include <stack>
#include <queue>
using namespace std;





int main()
{
	//Stack TestStack(20);

	//int i = 0;
	//while (!TestStack.IsFull())
	//{
	//	TestStack.Push(++i);
	//}

	//TestStack.Resize(20);

	//while (!TestStack.IsEmpty())
	//{
	//	cout << TestStack.Pop() << endl;
	//	//TestStack.Pop();
	//}

	ListStack<float> IntStack;
	for (int i = 1; i <= 3; ++i)
	{
		IntStack.Push(1.1f * float(i));
	}

	while (!IntStack.IsEmpty())
	{
		cout << IntStack.Pop() << endl;
	}

	queue<int> a;

	return 0;
}

