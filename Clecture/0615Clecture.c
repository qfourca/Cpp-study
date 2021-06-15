#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _p {
	char name[20];
	int x, y;
}Point;
int main()
{
	/*
	int arr[4] = { 1,2,3,4 };
	int* pArr = (int*)malloc(16);
	for (int i = 0; i < 4; i++)
	{
		pArr[i] = i * i;
		printf("pArr[i] = %d\n", pArr[i]);
	}*/
	Point p1, p2;
	strcpy(p1.name, "구조체 복사");
	p1.x = 10;
	p1.y = 20;
	//memcpy(&p2, &p1, sizeof(Point));
	p2.x = p1.x;
	p2.y = p2.y;
	strcpy(p2.name, p1.name);
	printf("%s\n", p2.name);
	printf("%d %d\n", p2.x, p2.y);
}