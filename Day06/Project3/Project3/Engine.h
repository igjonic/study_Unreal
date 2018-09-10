#pragma once
#include "Character.h"
#include <vector>

class Engine
{
public:
	Engine();
	~Engine();

	void Run();

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning;

	//Character* characters[200];
	//int TotalCharacterCount;

	std::vector<class Character*> characters;
};

