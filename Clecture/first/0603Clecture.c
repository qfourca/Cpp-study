#include <stdio.h>
/*
int isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (!(n % i))
			return 0;
	return 1;
}
int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n < 2)
			return 0;
		if (n > 1000)
			continue;
		int i, j, prime = 1;
		for (i = 2; i <= n; i++)
		{
			prime = 1;
			for (j = 2; j * j <= i; j++)
			{
				if (i % j == 0)
					prime = 0;
			}
			if (prime == 1)
				printf("%3d", i);
		}
		printf("\n");
	}
	return 0;
}
*/