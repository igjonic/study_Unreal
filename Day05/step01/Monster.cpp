#include "Monster.h"
#include <stdlib.h>
#include "Map.h"
#include <Windows.h>
#include <iostream>



Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::Init()
{
}

void Monster::Move(class Map* map)
{
	int dir = rand() % 4;
	if (dir == 0) //UP
	{
		if (!map->IsWall(X, Y - 1))
		{
			Y--;
		}
	}
	else if (dir == 1) //Down
	{
		if (!map->IsWall(X, Y + 1))
		{
			Y++;
		}
	}
	else if (dir == 2) //Left
	{
		if (!map->IsWall(X - 1, Y))
		{
			X--;
		}
	}
	else if (dir == 3) //Right
	{
		if (!map->IsWall(X + 1, Y))
		{
			X++;
		}
	}
}

void Monster::Draw()
{
	//커서위치를 플레이어 위치로 변경
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//콘솔 출력 색상 변경(Player색깔)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	std::cout << "M";
	//콘솔 출력 색상 변경(기본 칼라로 변경)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
