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
	cout << "���� ����" << endl;

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
	cout << "���� ����" << endl;

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
		
		//�������Ӿ� ó��
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
	cout << "�Է� �޴´�." << endl;
	Player* player = dynamic_cast<Player*>(characters[0]);
	if (player != nullptr)
	{
		player->Input();
	}
}

void Engine::Tick()
{
	cout << "�������� ���� ó��(Tick)" << endl;
	for (int i = 0; i < characters.size(); ++i)
	{
		characters[i]->Tick();
	}
}

void Engine::Render()
{
	cout << "ȭ�鿡 �׸���." << endl;
	for (int i = 0; i < characters.size(); ++i)
	{
		characters[i]->Draw();
	}
}
