#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printArr(int value[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
		printf("%3d", value[i]);

}
void selectionSort(int* value, int n)
{
	int i, j, min = 0, t = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (value[min] > value[j])
				min = j;
		}
		t = value[i];
		value[i] = value[min];
		value[min] = t;
	}
}
int main()
{
	int value[] = { 4,7,9,11,3,7,6 };
	int n = sizeof(value) / sizeof(int);
	printArr(value, n);
	printf("\n");
	selectionSort(value, n);
	printArr(value, n);
	return 0;
}