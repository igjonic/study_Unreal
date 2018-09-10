#pragma once
#include <string>
#include "Character.h"

class Player: public Character
{
public:
	Player();
	~Player();

	void Input();
	virtual void Tick() override;
	virtual void Draw() override;

protected:
	void Skill1();
};

