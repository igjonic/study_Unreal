#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define MAX 10

int Map[MAX][MAX] =
{
	{0, 0, 1, 1, 1, 0, 1, 1, 0, 0 },
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{1, 1, 1, 1, 1, 0, 0, 1, 0, 0 },
	{0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
	{0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
	{0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
	{0, 0, 0, 0, 0, 0, 0, 1, 3, 1 }
};

int CountCell(int x, int y)
{
	if (x < 0 || x >= MAX || y < 0 || y >= MAX) //범위 넘어서면 안 세고
	{
		return 0;
	}
	else if (Map[y][x] != 1) //이미지가 아니면 안세고
	{
		return 0;
	}
	else
	{
		Map[y][x] = 2; // 현재 숫자를 셌다.
		return 1 + CountCell(x, y - 1) + CountCell(x + 1, y)
			+ CountCell(x, y + 1) + CountCell(x - 1, y) //위, 아래, 왼쪽, 오른쪽
			+ CountCell(x - 1, y - 1) + CountCell(x + 1, y - 1)
			+ CountCell(x + 1, y + 1) + CountCell(x - 1, y + 1); //대각선 방향
	}

	return 0;
}

void RFill(int x, int y)
{
	if (x < 0 || x >= MAX || y < 0 || y >= MAX) //범위 넘어서면 안 세고
	{
		return;
	}
	else if (Map[y][x] != 0) // 색칠 이미 되어 있으면 아무것도 안함
	{
		return;
	}
	else //현재 위치 색칠하고 4방향 탐색
	{
		Map[y][x] = 1;

		RFill(x, y - 1);
		RFill(x+1, y);
		RFill(x, y+1);
		RFill(x-1, y);
	}
}

void PrintMap()
{
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << Map[y][x] << " ";
		}
		cout << endl;
	}
}

void PutPixel(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("#");
}

void RLine(int StartX, int StartY, int EndX, int EndY)
{
	if (abs(StartX - EndX) <= 1 && abs(StartY - EndY) <= 1)
	{
		PutPixel(StartX, StartY);
		PutPixel(EndX, EndY);
		return;
	}
	else
	{
		PutPixel((StartX + EndX) / 2, (StartY + EndY) / 2);
		RLine(StartX, StartY, (StartX + EndX) / 2, (StartY + EndY) / 2);
		RLine((StartX + EndX) / 2, (StartY + EndY) / 2, EndX, EndY);
	}
}

int main()
{
	PutPixel(5, 5);
	RLine(0, 0, 10, 15);
	getch();
	return 0;
}