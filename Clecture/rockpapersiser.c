#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // time
#include <stdlib.h> // srand
int win, draw, lose;
void Match(int human, int cum)
{
	int x = human - cum;
	switch (x)
	{
	case 0:
		draw++;
		printf("�����ϴ�(%d�� %d�� %d��)\n", win, draw, lose);
		break;
	case 1:
	case -2:
		win++;
		printf("����� �̰����ϴ�(%d�� %d�� %d��)\n", win, draw, lose);
		break;
	default:
		lose++;
		printf("����� �����ϴ�(%d�� %d�� %d��)\n", win, draw, lose);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int time;
	int myhand, cpuhand;
	printf("���������� ������ �� �� �����Ͻðڽ��ϱ�?");
	scanf("%d", &time);
	for (int i = 0; i < time; i++)
	{
		printf("(1:����, 2:����, 3:��) :"); //01 10 11
		cpuhand = (rand() % 3) + 1;
		scanf("%d", &myhand);
		Match(myhand, cpuhand);
	}
}