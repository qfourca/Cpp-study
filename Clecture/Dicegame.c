#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> // time
#include <stdlib.h> // srand
int dbl(int a,int b)
{
	int c = (rand() % 6) + 1;
	int d = (rand() % 6) + 1;
	printf("�����Դϴ�\n�ֻ���:%d %d\n", c, d);
	if (c == d)
		return dbl(a + b, c + d);
	else
		return a + b + c + d;
}
int main()
{
	srand((unsigned int)time(NULL));
	char input;
	int randumNum1, randumNum2;
	for (;;)
	{
		printf("�ֻ��� ������ �Ͻðڽ��ϱ�?(Y/N)");
		scanf("%c", &input);
		getchar();
		if (input == 'N' || input == 'n')
			break;
		randumNum1 = (rand() % 6) + 1;
		randumNum2 = (rand() % 6) + 1;
		if (randumNum1 == randumNum2)
		{
			printf("�ֻ���:%d %d \n", randumNum1, randumNum2);
			printf("%d ĭ �����ϼ���\n\n", dbl(randumNum1, randumNum2));
			continue;
		}
		printf("�ֻ���:%d %d\n%d ĭ �����ϼ���\n\n", randumNum1, randumNum2, randumNum1 + randumNum2);
	}
	return 0;
}