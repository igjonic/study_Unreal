#include<iostream>
#include<string>
using namespace std;

int RSum(int n)
{
	if (n == 1)
	{
		return n;
	}
	else
	{
		return n + RSum(n - 1);
	}
}
void ReversPrint(string msg)
{
	//for (int i = msg.length()-1; i >= 0; --i)
	//{
	//	cout << msg.substr(i, 1);
	//}
	//cout << endl;
}
void RReversPrint(string msg)
{
	if (msg.length() == 0)
	{
		return;
	}
	RReversPrint(msg.substr(1));
	cout << msg[0];
}
int RArrySum(int* num, int Size)
{
	if (Size == 0)
	{
		return 0;
	}
	
	return RArrySum(num, Size - 1) + num[Size - 1];
}
int RStringLength(char* str)
{
	if (str[0] == '\0')
	{
		return 0;
	}
	return 1 + RStringLength(str + 1);
}

void ToBinary(int n)
{
	if (n<=1)
	{
		cout << n;
		return;
	}
	ToBinary(n / 2);
	cout << n % 2;
}
int Factorial(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; ++i)
	{
		sum*= i;
	}
	return sum;
}
int RFactorial(int n)
{
	if (n == 1)
	{
		return n;
	}
	return n*RFactorial(n - 1);
}
int RSearch(int* Data, int Size,int target )
{
	if (Size == 0)
	{
		return -1;
	}
	if (Data[Size - 1] == target)
	{
		return Size - 1;
	}
	return RSearch(Data, Size - 1, target);
}
int RSearch2(int* Data, int begin, int end, int target)
{
	if (begin > end)
	{
		return -1;
	}
	else if (Data[begin] == target)
	{
		return begin;
	}
	else
	{
		RSearch2(Data, begin + 1, end, target);
	}
}
int RSearch3(int* Data, int begin, int end, int target)
{
	if (begin > end)
	{
		return -1;
	}
	else
	{
		int middle = (begin + end) / 2;
		if (Data[middle] == target)
		{
			return middle;
		}
		int index = RSearch3(Data, begin, middle - 1, target);
		if(index!=-1)
		{
			return index;
		}
		else
		{
			return RSearch3(Data, middle + 1, end, target);
		}
	}
}
int BSearch(int* Data, int begin, int end, int target)
{
	if (begin > end)
	{
		return -1;
	}
	else
	{
		int middle = (begin + end) / 2;
		if (Data[middle] == target)
		{
			return middle;
		}
		if (Data[middle]>target)
		{
			return BSearch(Data, begin, middle - 1, target);
		}
		else
		{
			return BSearch(Data, middle + 1, end, target);
		}
	}
}
int main()
{
	//char str[] = "Hell";
	//cout << RStringLength(str) << endl;
	//int num[] = {6, 5, 7, 8, 9};
	ToBinary(10);
}