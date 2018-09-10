#include "Character.h"

#include <iostream>

using namespace std;

Character::Character()
{
	cout << "캐릭터 생성" << endl;
	SetName("캐릭터");
}


Character::~Character()
{
	cout << "캐릭터 삭제" << endl;
}

void Character::Tick()
{
	cout << "캐릭터 처리" << endl;
}

void Character::Draw()
{
	cout << "캐릭터 그리기" << endl;
}

void Character::SetName(std::string newName)
{
	cout << "캐릭터 이름" << endl;
	name = newName;
}

std::string Character::GetName()
{
	return name;
}

void Character::Move()
{
	cout << "캐릭터 이동" << endl;
}
