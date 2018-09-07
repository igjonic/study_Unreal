#pragma once
#include "Job.h"

class Player
{
public:
	Player();
	~Player();

	int x;
	int y;

	EJob job;

	void Move(int KeyCode, class Map* map);

	void Draw();

	void Init();
};

