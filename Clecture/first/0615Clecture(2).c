#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STU
{
	char name[20];
	int he;
	double we;
}Stu;

Stu stu[5];
void input()
{
	for (int i = 0; i < 5; i++)
		scanf("%s %d %lf", stu[i].name, &stu[i].he, &stu[i].we);
}
void sort()
{
	Stu temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (stu[i].he > stu[j].he)
			{
				memcpy(&temp, &stu[i], sizeof(Stu));
				memcpy(&stu[i], &stu[j], sizeof(Stu));
				memcpy(&stu[j], &temp, sizeof(Stu));


			}
		}
	}
}