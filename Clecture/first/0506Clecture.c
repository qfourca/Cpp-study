#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	/*
	int arr[10] = { 0 };
	int temp;
	for (;;)
	{
		scanf("%d", &temp);
		if (temp >= 1 && temp <= 10)
			arr[temp - 1]++;
		else
			break;
	}
	for (int i = 1; i < 10; i++)
		if (arr[i] != 0)
			printf("%d : %d��\n", i + 1, arr[i]);
	return 0;
	*/

	int arr[3][3] = { 0 };
	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("%d�� �л� : ", i);
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	printf("     ����   ��C   ����   ����\n");
	for (int i = 0; i < 3; i++)
		printf("%d��  %4d%6d%6d%8d\n",i+1, arr[i][0], arr[i][1], arr[i][2], arr[i][0] + arr[i][1] + arr[i][2]);
	printf("�հ� ");
	for (int i = 0; i < 3; i++)
		printf("%3d    ", arr[0][i] + arr[1][i] + arr[2][i]);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			x += arr[i][j];
	printf("%d", x);
	return 0;
	*/
}