#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZEX 10
#define MAXSIZEY 10

#define UP    0x48
#define DOWN  0x50
#define LEFT  0x4B
#define RIGHT 0x4D

typedef struct tagVector2D {
	int X;
	int Y;
}FVector;

FVector PlayerPosition;
int map[MAXSIZEX][MAXSIZEY] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 3, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool bIsRunning = true;
int Input()
{
	int key = _getch();
	return key;
}

void Process(int keyCode)
{
	//종료한다
	if (keyCode == 'q'||keyCode=='Q')
	{
		bIsRunning = false;
	}
	//이동
	else if (keyCode == UP)
	{
		if (map[PlayerPosition.Y - 1][PlayerPosition.X] != 1)
		{
			PlayerPosition.Y--;
		}
	}
	else if (keyCode == DOWN)
	{
		if (map[PlayerPosition.Y + 1][PlayerPosition.X] != 1)
		{
			PlayerPosition.Y++;
		}
	}
	else if (keyCode == LEFT)
	{
		if (map[PlayerPosition.Y][PlayerPosition.X - 1] != 1)
		{
			PlayerPosition.X--;
		}
	}
	else if (keyCode == RIGHT)
	{
		if (map[PlayerPosition.Y][PlayerPosition.X + 1] != 1)
		{
			PlayerPosition.X++;
		}
	}
	if (map[PlayerPosition.Y][PlayerPosition.X] == 3)
	{
		bIsRunning = false;
	}
}
void Rendering()
{
	//화면 지우기
	system("cls");
	for (int y = 0; y < MAXSIZEY; ++y)
	{
		for (int x = 0; x < MAXSIZEX; ++x)
		{
			if (map[y][x] == 1) //현재 출력 위치에 정보에 벽이냐?
			{
				printf("%d", map[y][x]);
			}
			else if (y == PlayerPosition.Y && x == PlayerPosition.X)
			{
				printf("P");
			}
			else if (map[y][x] == 3)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}

int main()
{
	PlayerPosition.X = 1;
	PlayerPosition.Y = 1;
	while (bIsRunning)
	{
		int keyCode = Input();
		Process(keyCode);
		Rendering();
	}
	return 0;
}