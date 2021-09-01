#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
int n;
int f()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += i;
	return ans;
}
int main()
{
	scanf("%d", &n);
	printf("%d\n",f(n));
	return 0;
}*/
/*
int n, d[110];
int f()
{
	int max = 0;
	for (int i = 0; i < n; i++)
		if (d[i] > max)
			max = i;
	return max;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	printf("%d", f());
	return 0;
}*/
/*
int main()
{
	int n;
	scanf("%d", &n);
	printf("*\n");
	for (int i = 0; i < n-2; i++)
	{
		printf("*");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < n; i++)
		printf("*");
	return 0;
}*/
int main()
{
	int arr[100][100] = { 0 };
	int a, b;
	scanf("%d %d", &a, &b);
	int ai = 1;
	int bi = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = i + 1;
		}
		printf("%d\n", ai);
		ai += (i + 1);
	}
	// 0 0
	
	// 1 0
	// 0 1
	
	// 2 0
	// 1 1
	// 0 2
	 
	// 3 0
	// 2 1
	// 1 2
	// 0 3
}