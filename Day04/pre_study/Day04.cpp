#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Util.h"
int main()
{
	int a;
	int *Num; 
	long long Total=0;
	float avg = 0;
	int count = 0;
	
	scanf("%d", &a);

	while (a < 3 || a > 10000)
	{
		scanf("%d", &a);
	} 
	
	Num = (int*)malloc(sizeof(int) * a);

	for (int i = 0; i < a; i++)
	{
		do{
			scanf("%d", &Num[i]);
		} while (Num[i] < 0 || Num[i] > 10000000);
		Total = Total + Num[i];
		count++;
	}
	
	avg = Total/(float)count;
	printf("출력\n");
	printf("합:%.lld\n",Total);
	printf("평균:%f\n", avg);	
	free(Num);
}

