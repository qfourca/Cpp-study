#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _m {
	int num;
	int money;
}acc;
acc maxMoney(acc m[], int n)
{
	acc King = m[0];
	for (int i = i; i < n; i++)
	{
		if (king.money < m[i].money)
			king = m1[i];
	}
	return king;
}
int main()
{
	acc m[5], king;
	for (int i = 0; i < 5; i++)
	{
		printf("���¹�ȣ�� �ݾ�\n");
		m[i].num = i;
		scanf("%d", &m[i].money);
	}
	king = maxMoney(m, 5);
	printf("����� %d�� %d�� \n", king.num, king.money);
	return 0;
}