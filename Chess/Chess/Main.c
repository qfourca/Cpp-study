#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

int main()
{
	Setting();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			DrawCharacter(i+1, j+1, Character[i][j]);
	DrawBorder(1, 1, 1);

	Sleep(100000);
}