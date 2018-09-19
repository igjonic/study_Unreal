#include<iostream>
#include<stdlib.h>

using namespace std;

void BubbleSort(int* data, int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = i; j < size-1; ++j)
		{
			if (data[j] > data[j+1])
			{
				swap(data[j+1], data[j]);
			}
			for (int k = 0; k < size; ++k)
			{
				cout << data[k] << ",";
			}
			cout << endl;
		}
	}
}

void SelectionSort(int* data, int size, bool (*fp)(int, int))
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			if (fp(data[i], data[j]))
			{
				swap(data[i], data[j]);
			}
			for (int k = 0; k < size; ++k)
			{
				cout << data[k] << ",";
			}
			cout << endl;
		}
	}
}
void test(int a, int b)
{
	cout << a + b << endl;
}
bool cmp(int a, int b)
{
	return a < b;
}
int partition(int* data, int begin, int end)
{
	int pivot = data[end];
	int min = begin - 1;
	for (int max = begin; max <= end - 1; ++max)
	{
		if (data[max] <= pivot)
		{
			min++;
			swap(data[min], data[max]);
		}
	}
	swap(data[min + 1], data[end]);
	return min + 1;
}
void quicksort(int* data, int begin,int end)
{
	if (begin < end)
	{
		//자료 나누기
		int pivot = partition(data, begin, end);
		quicksort(data, begin, pivot - 1);
		quicksort(data, pivot + 1, end);
	}
}

int main()
{
	void(*fp)(int, int);
	//UE4 Delegate UE4
	//void test(int a, int b);
	fp = test;
	fp(1, 2);
	int data[] = { 5,1,4,2,3 };
	//Bubble
   //Selection
	//BubbleSort(data, 5);
	//sort(data,data+5,less());
	quicksort(data, 0, 4);
	//SelectionSort(data, 5,cmp);
	for (auto i : data)
	{
		cout << i << ",";
	}
	return 0;
}
