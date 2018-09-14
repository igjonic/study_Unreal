#pragma once
#include <iostream>
using namespace std;
class Engine
{
public:
	Engine();
	~Engine();
	void Run();
	bool bIsRunning;
private:
	int Input();
	void Process(int keyCode);
	void Render();
};

