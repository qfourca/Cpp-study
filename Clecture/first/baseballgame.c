#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // time
#include <stdlib.h> // srand
int main()
{
	srand((unsigned int)time(NULL));
	char input;
	int randNum[3] = { 0 };
	int myNum[3] = { 0 };
	printf("야구 게임을 하시겠습니까?(Y/N)");
	scanf("%c", &input);
	if (input == 'N' || input == 'n')
		return 0;
	for (int i = 0; i < 3; i++)
	{
		randNum[i] = rand() % 8 + 1;
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			else if (randNum[i] == myNum[j])
				i--;
		}
	}
	for (;;)
	{
		int match[3] = { 0 };
		printf("세 숫자를 입력하세요");
		scanf("%d %d %d", &myNum[0], &myNum[1], &myNum[2]);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (randNum[i] == myNum[j])
					if (i == j)
					{
						match[0]++;
						continue;
					}
					else
					{
						match[1]++;
						continue;
					}
			}
		if (match[0] == 3)
		{
			printf("승리하였습니다\n");
			return 0;
		}
		match[2] = (3 - (match[0] + match[1]));
		printf("스트라이크 : %d 볼 : %d 아웃 : %d\n", match[0], match[1], match[2]);
	}
	return 0;
}