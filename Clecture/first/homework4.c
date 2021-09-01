#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 20
int main(void) //도수분포표
{
	int a[NUM] = { 67,87,45,100,54,45,60,23,56,78,0,1,10,12,99,77,98,95,92,5 };
	int i, range, i, histo[11];
	for (int i = 0; i <= 10; i++)
		histo[i] = 0;
	for (int i = 0; i < NUM; i++)
		histo[a[i] / 10]++;
	for (int i = 0; i <= 10; i++)
	{
		printf("%3d: %3d\n", i * 10, histo[i]);
	}
	return 0;
}