#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[] = { 44,88,30,75,35,50,65,78,49,59,60,91,58,56,87,95,69,78,77,75 };
	int histo[11] = { 0 };
	int n = sizeof(score) / sizeof(int);
	for (int i = 0; i < n; i++)
	{
		histo[score[i] / 10]++;
	}
	for (int i = 0; i < 11; i++)
	{
		printf("%3d : %3d\n", i * 10, histo[i]);
	}
	return 0;
}