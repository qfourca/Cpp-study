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
	printf("�ִ����� : %d\n", gcd(a, b));
	printf("�ִ����� : %d\n", a * b / gcd(a, b));
}