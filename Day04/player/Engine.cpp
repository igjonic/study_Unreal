#include "Engine.h"



Engine::Engine()
{
	cout << "��������" << endl;
	bIsRunning = true;
}


Engine::~Engine()
{
	cout << "�Ҹ�" << endl;
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
