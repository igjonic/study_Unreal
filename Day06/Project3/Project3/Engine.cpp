#include "Engine.h"
#include "Player.h"
#include "Goblin.h"
#include "Slime.h"

#include <iostream>
#include <conio.h>
#include "Character.h"
#include <time.h>

using namespace std;

Engine::Engine()
{
	cout << "엔진 생성" << endl;

	bIsRunning = true;


	characters.push_back(new Player());
	srand(time(nullptr));
	int GoblinCount = rand() % 5;
	int SlimeCount = rand() % 5;
	for (int i = 0; i < GoblinCount; ++i)
	{
		characters.push_back(new Goblin());
	}
	for (int i = 0; i < SlimeCount; ++i)
	{
		characters.push_back(new Slime());
	}

	//characters[0] = new Player();
	//characters[1] = new Goblin();
	//characters[2] = new Slime();
	//characters[3] = new Slime();
	//characters[4] = new Slime();
	//characters[5] = new Slime();
}


Engine::~Engine()
{
	cout << "엔진 제거" << endl;

	for (int i = 0; i < characters.size(); ++i)
	{
		delete characters[i];
	}
}

void Engine::Run()
{
	while (bIsRunning) //GameLoop, MessageLoop
	{
		Input();
		Tick();
		Render();
		
		//한프레임씩 처리
		cout << "------------------------------------------------\n\n" << endl;
		int KeyCode = _getch();
		if (KeyCode == 'q')
		{
			bIsRunning = false;
		}
	}
}

void Engine::Input()
{
	cout << "입력 받는다." << endl;
	Player* player = dynamic_cast<Player*>(characters[0]);
	if (player != nullptr)
	{
		player->Input();
	}
}

void Engine::Tick()
{
	cout << "매프레임 엔진 처리(Tick)" << endl;
	for (int i = 0; i < characters.size(); ++i)
	{
		characters[i]->Tick();
	}
}

void Engine::Render()
{
	cout << "화면에 그린다." << endl;
	for (int i = 0; i < characters.size(); ++i)
	{
		characters[i]->Draw();
	}
}
