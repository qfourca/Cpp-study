#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	for (int i = 2; i < 100; i++)
		if (prime(i))
			printf("%4d", i);
	return 0;
}

	