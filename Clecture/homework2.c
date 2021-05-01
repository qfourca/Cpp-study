#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char word[50];
	int ans = 0;
	scanf("%s", word);
	for (int i = 0; i < 50; i++)
	{
		if (word[i] >= 97 && word[i] <= 122)//97 122
		{
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}