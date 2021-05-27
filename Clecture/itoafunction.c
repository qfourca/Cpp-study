#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	//gets(buffer, 256);
	//i = atoi(buffer);
	scanf("%d", &i);
	_itoa(i, buffer, 10);
	printf("decimal: %s\n", buffer);
	_itoa(i, buffer, 16);
	printf("hexadecimal: %s\n", buffer);
	_itoa(i, buffer, 2);
	printf("binary: %s\n", buffer);
	return 0;
}

	
