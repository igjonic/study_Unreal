#include "Player.h"
#include <iostream>
#include <Windows.h>
#include "Map.h"

#define UP		0x48
#define DOWN	0x50
#define LEFT	0x4B
#define RIGHT	0x4D


Player::Player()
{
	Init();
}


Player::~Player()
{
}

void Player::Move(int KeyCode, class Map* map)
{
	if (KeyCode == UP)
	{
		//���� ��ĭ ���� ���� ������ Ȯ��
		if (!map->IsWall(x, y - 1))
		{
			y--;
		}
	}
	else if (KeyCode == DOWN)
	{
		if (!map->IsWall(x, y + 1))
		{
			y++;
		}
	}
	else if (KeyCode == LEFT)
	{
		if (!map->IsWall(x-1,y))
		{
			x--;
		}
	}
	else if (KeyCode == RIGHT)
	{
		if (!map->IsWall(x + 1, y))
		{
			x++;
		}
	}
}

void Player::Draw()
{
	//Ŀ����ġ�� �÷��̾� ��ġ�� ����
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

	//�ܼ� ��� ���� ����(Player����)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << "P";
	//�ܼ� ��� ���� ����(�⺻ Į��� ����)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Player::Init()
{
	x = 1;
	y = 1;
	job = EJob::Farmer;
}
