#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster()
{
	cout << "���� ����" << endl;
	SetName("����");
}


Monster::~Monster()
{
	cout << "���� ����" << endl;
}

void Monster::GiveItem()
{
	cout << "���Ͱ� ������ ����" << endl;
}
