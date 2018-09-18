#include<iostream>
#include<bitset>
#include<string>
using namespace std;
string* findmap(int n, int* arry1, int* arry2)
{
	int* arry3 = new int[n];
	string* result = new string[n];
	for (int i = 0; i < n; ++i)
	{
		arry3[i] = arry1[i] | arry2[i];
		result[i]=bitset<16>(arry3[i]).to_string();
		result[i] = result->substr(16 - n, n);
		for (int len = 0; len < result[i].length(); ++len)
		{
			result[i][len] = result[i][len] == '1' ? '#' : ' ';
		}
	}
	delete[] arry3;
	return result;
}
int main()
{
	int n = 5;
	int arry1[] = { 9, 20, 28, 18, 11 };
	int arry2[] = { 30, 1, 21, 17, 28 };
	string* result = findmap(n, arry1, arry2);
	for (int i = 0; i < n; ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}