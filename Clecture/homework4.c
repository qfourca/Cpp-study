#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[3] = { 'a','b','c' };
	char ptr = str[0];

	for (int i = 0; i < 3; i++)
	{
		printf("%c\n", *(str+i));
	}


	return 0;
}