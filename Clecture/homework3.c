#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char str[3][10] = { "abc","123","¤¡¤¤¤§" };
	char* pStr[3] = { str[0],str[1],str[2] };
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);

	for (int i = 0;i<3;i++)
	{
		printf("%s\n", *(pStr+i));
	}


	return 0;
}