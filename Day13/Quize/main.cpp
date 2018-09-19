#include<iostream>
#include <Windows.h>
#include<queue>
#define MAX 10
int Map[MAX][MAX] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int Map2[MAX][MAX] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

using namespace std;
void PutPixel(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("#");
}
int CountCell(int x, int y)
{
	if (x < 0 || x >= MAX || y < 0 || y >= MAX)
	{
		return 0;
	}
	else if (Map[x][y] != 1)
	{
		return 0;
	}
	else
	{
		Map[x][y] = 2;
		return 1 + CountCell(x, y-1) + CountCell(x+1, y) + CountCell(x, y+1) + CountCell(x-1, y)+
			CountCell(x-1, y - 1) + CountCell(x + 1, y+1) + CountCell(x-1, y + 1) + CountCell(x - 1, y-1);
	}
	return 0;
}
void RFill(int x, int y)
{
	if (x < 0 || x >= MAX || y < 0 || y >= MAX)
	{
		return;
	}
	else if (Map2[x][y] != 0)
	{
		return;
	}
	else
	{
		Map2[x][y]=1;

		RFill(x, y - 1);
		RFill(x+1, y);
		RFill(x, y+1);
		RFill(x-1, y);
	}
}
void Rline(int StartX, int StartY, int EndX, int EndY)
{
	if (abs(StartX - EndX) <= 1 && abs(StartX - EndY) <= 1)
	{
		//PutPixel(StartX, StartY);
		//PutPixel(EndX, EndY);
		return;
	}
	else
	{
		//PutPixel((StartX + EndX) / 2, (StartY + EndY) / 2);
	
		Rline(StartX, StartY, (StartX + EndX) / 2, (StartY + EndY) / 2);
		Rline((StartX + EndX) / 2, (StartY + EndY) / 2,EndX,EndY);
	}
}
void PrintMap()
{
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << Map2[y][x] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Rline(0, 0, 5, 5);
	return 0;
}