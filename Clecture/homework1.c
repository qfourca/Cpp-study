#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char word[50] = 0;
	char max = 0;
	scanf("%s", word);
	for (int i = 0; i < 50; i++)
	{
		if (word[i] > max)
		{
			max = word[i];
		}
	}
	printf("%c",max);
}