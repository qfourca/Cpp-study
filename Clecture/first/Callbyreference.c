#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap1(int, int);//call by value
void swap2(int*, int*);//call by reference

int main()
{
	int a = 5, b = 8;
	swap1(a, b);
	printf("a = %d, b = %d\n", a, b);
	swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
void swap1(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}
void swap2(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}