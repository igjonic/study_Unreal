#pragma once
#include "Job.h"
#include "Character.h"

class Player:public Character
{
public:
	Player();
	~Player();

	//int x;
	//int y;

	EJob job;

	virtual void Draw() override;

	virtual void Init() override;
};

