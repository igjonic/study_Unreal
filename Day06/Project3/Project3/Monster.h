#pragma once
#include "Character.h"

class Monster : public Character
{
public:
	Monster();
	~Monster();

protected:
	void GiveItem();
};

