#include "Engine.h"



Engine::Engine()
{
	cout << "엔진생성" << endl;
	bIsRunning = true;
}


Engine::~Engine()
{
	cout << "소멸" << endl;
}

void Engine::Run()
{
	while (bIsRunning)
	{
		cout << "Running" << endl;
		int keyCode = Input();
		Process(keyCode);
		Render();
	}
}

int Engine::Input()
{
	return 0;
}

void Engine::Process(int keyCode)
{
}

void Engine::Render()
{
}
