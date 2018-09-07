#pragma once

class Engine
{
public:
	Engine();
	~Engine();

	void Run();

	class Map* map;
	class Player* player;
	class Goal* goal;
	class Monster* monster;

private:
	int Input();
	void Process(int KeyCode);
	void IsQuit(int KeyCode);
	void IsComplete();
	void Render();
	void InitGoalPosition();
	void InitMonstersPosition();
	void IsFail();
	bool bIsRunnging;
};

