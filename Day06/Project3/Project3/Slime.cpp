#include "Slime.h"
#include <iostream>

using namespace std;

Slime::Slime()
{
	cout << "슬라임 생성" << endl;
	SetName("슬라임");
}


Slime::~Slime()
{
	cout << "슬라임 삭제" << endl;
}

void Slime::Tick()
{
	cout << name << " 처리" << endl;
}

void Slime::Draw()
{
	cout << name << " 그리기" << endl;
}
