#include "Character.h"

#include <iostream>

using namespace std;

Character::Character()
{
	cout << "ĳ���� ����" << endl;
	SetName("ĳ����");
}


Character::~Character()
{
	cout << "ĳ���� ����" << endl;
}

void Character::Tick()
{
	cout << "ĳ���� ó��" << endl;
}

void Character::Draw()
{
	cout << "ĳ���� �׸���" << endl;
}

void Character::SetName(std::string newName)
{
	cout << "ĳ���� �̸�" << endl;
	name = newName;
}

std::string Character::GetName()
{
	return name;
}

void Character::Move()
{
	cout << "ĳ���� �̵�" << endl;
}
