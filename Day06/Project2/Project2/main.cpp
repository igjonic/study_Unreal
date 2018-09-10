#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0; //숫 갯수
	unsigned long long InputNumber; // 입력숫자
	unsigned long long Result; //계산 결과

	vector<unsigned long long> X;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> InputNumber;
		X.push_back(InputNumber);
	}

	for (int i = 0; i < X.size(); ++i)
	{
		unsigned long long  choice = 0;
		for (int bit = 1; bit < 64; ++bit)
		{
			choice = 1LL << bit;
			//choice = pow(2, bit);
			if (choice >= X[i])
			{
				if (i == 0)
				{
					Result = choice;
				}
				else
				{
					Result ^= choice;
				}
				break;
			}
		}
	}

	cout << Result << endl;


	return 0;
}