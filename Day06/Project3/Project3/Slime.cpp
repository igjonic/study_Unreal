#include "Slime.h"
#include <iostream>

using namespace std;

Slime::Slime()
{
	cout << "������ ����" << endl;
	SetName("������");
}


Slime::~Slime()
{
	cout << "������ ����" << endl;
}

void Slime::Tick()
{
	cout << name << " ó��" << endl;
}

void Slime::Draw()
{
	cout << name << " �׸���" << endl;
}
