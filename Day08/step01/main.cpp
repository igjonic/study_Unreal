//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> a;
//	int b[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	for (auto iter : b)
//	{
//		cout << iter << endl;
//	}
//	
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	a.insert(find(a.begin(), a.end(), 2), 20);
//	//a.erase(find(a.begin(), a.end(), 2));
//	cout << a.size() << endl;
//	for (int i = 0; i < 2; ++i)
//	{
//		cout << a[i] << endl;
//	}
//	//vector<int>::iterator iter;
//	//for (auto iter = a.rbegin(); iter != a.rend(); ++iter)
//	//for (auto iter = a.begin(); iter != a.end(); ++iter)
//	return 0;
//}
#include<iostream>
#include"Myvector.h"
#include"MyT.h"
#include"MyVectorT.h"
using namespace std;
template<typename T>

void Swap(T& a,T& b)
{
	T t = a;
	a = b;
	b = t;
}
int main()
{
	
	//int a = 10;
	//int b = 20;
	//cout << a << "," << b << endl;
	//Swap<int>(a, b);
	//cout << a << "," << b << endl;

	//float c = 10;
	//float d = 20;
	//cout << c << "," << d << endl;
	//Swap<float>(c, d);
	//cout << c << "," << d << endl;
	//MyVector a;
	//a.PushBack(1);
	//a.PushBack(2);
	//a.PushBack(3);
	//a.PushBack(4);
	//a.PushBack(5);
	//a.PushBack(6);
	//a.PushBack(7);
	//a.PushBack(8);
	//a.PushBack(9);

	//for (int i = 0; i < a.GetSize(); ++i)
	//{
	//	cout << a.GetValue(i) << endl;
	//}
	//for (int i = 0; i < 100; ++i)
	//{
	//	a.PushBack(i);
	//}
	//int b = a.Find(10);
	//cout << b << endl;
	//a.Erase(a.Find(10));
	//for (int i = 0; i < 100; ++i)
	//{
	//	cout << a.GetValue(i) << " ";
	//}

	//MyT<int, float> a;
	//MyT<float, int> b;
	MyVectorT<int> intMyVector;
	MyVectorT<float> floatMyVector;
	//MyVectorT<string> stringMyVector;

	for (int i=0; i < 100; ++i)
	{
		intMyVector.PushBack(i);
	}

	cout << intMyVector[10] << endl;
	return 0;
}