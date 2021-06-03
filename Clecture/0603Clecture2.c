#include <stdio.h>
int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}
int main()
{
	int a = 16, b = 4;
	printf("최대공약수 : %d\n", gcd(a, b));
	printf("최대공배수 : %d\n", a * b / gcd(a, b));
}