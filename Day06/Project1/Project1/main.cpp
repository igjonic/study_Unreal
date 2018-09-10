#include <iostream>
#include <bitset>
#include <algorithm>
#include <conio.h>

using namespace std;
typedef unsigned char byte;

#define O1			1 << 0 //0000 0001 , 1
#define O2			1 << 1 //0000 0010 , 2
#define O3			1 << 2 //0000 0100 , 4
#define O4			1 << 3 //0000 1000 , 8
#define O5			1 << 4 //0001 0000 , 16
#define O6			1 << 5 //0010 0000 , 32
#define O7			1 << 6 //0100 0000 , 64
#define O8			1 << 7 //1000 0000 , 128


int main()
{
	byte option = O1 | O2 | O5;

	if (option & (O3 | O7))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}

int clamp(int x, int min, int max)
{
	if (x < min)
	{
		x = min;
	}
	else if (x > max)
	{
		x = max;
	}
	else
	{
		x = x;
	}

	return x;
}

int main2()
{
	byte a = 0x01;
	int pos = 0; // 0 =< pos < 8

	while (true)
	{
		int KeyCode = _getch();
		if (KeyCode == 'a')
		{
			pos++;
			pos = clamp(pos, 0, 7);

			cout << bitset<8>(1 << pos) << endl;
		}
		else if (KeyCode == 'd')
		{
			pos--;
			pos = clamp(pos, 0, 7);

			cout << bitset<8>(1 << pos) << endl;
		}
		else if(KeyCode == 'q')
		{
			break;
		}
	}

	return 0;
}