#include<stdio.h>
#include "Util.h"

void DrawLine(int a)
{
	for (int i = 0; i < a; i++)
	{
		DrawStar(i+1);
		printf("\n");
	}
}

void DrawStar(int a)
{
	char star = '*';
	for (int i = 0; i < a; i++)
	{
		printf("%c",star);
	}
}
