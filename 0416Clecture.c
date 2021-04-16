#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*int main()
{
	int x = 5;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("*");
		for (int k = 0; k < x; k++)
			printf(" ");
		printf("*\n");
		x-=2;
	}
	printf("   *\n");
	x = 1;
	for (int i = 2; i > -1; i--)
	{
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("*");
		for (int k = 0; k < x; k++)
			printf(" ");
		printf("*\n");
		x += 2;
	}
}*/
//
//2중 for 문 0 1 2 "
//"*" 출력
//for 문 5 3 1""
/*int main()
{
	for (int a = 1;a<10;a++)
	{
		for (int i = 2; i < 10; i++)
		{
			printf("%d * %d = %3d   ", i, a, a * i);
		}
		printf("\n");
	}
	return 0;
}*/
int main()
{
	int num;
	scanf("%d", &num);
	num++;
	for (int a = 1; a < num; a++)
	{
		for (int i = 1; i < num; i++)
		{
			printf("(%d, %d) ",a,i);
		}
		printf("\n");
	}
	return 0;
}