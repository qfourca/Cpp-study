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
		printf("비겼습니다(%d승 %d무 %d패)\n", win, draw, lose);
		break;
	case 1:
	case -2:
		win++;
		printf("당신이 이겼겼습니다(%d승 %d무 %d패)\n", win, draw, lose);
		break;
	default:
		lose++;
		printf("당신이 졌습니다(%d승 %d무 %d패)\n", win, draw, lose);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int time;
	int myhand, cpuhand;
	printf("가위바위보 게임을 몇 번 실행하시겠습니까?");
	scanf("%d", &time);
	for (int i = 0; i < time; i++)
	{
		printf("(1:가위, 2:바위, 3:보) :"); //01 10 11
		cpuhand = (rand() % 3) + 1;
		scanf("%d", &myhand);
		Match(myhand, cpuhand);
	}
}