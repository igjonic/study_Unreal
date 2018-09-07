#pragma once
class Monster
{
public:
	Monster();
	~Monster();

	int X;
	int Y;
	void Init();
	void Move(class Map* map);
	void Draw();
};

