#pragma once
#include <string>
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();
	~Goblin();

	virtual void Tick() override;
	virtual void Draw() override;
};

