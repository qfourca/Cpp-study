#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Drawing.hpp"

void DrawCharacter(char x, int y, char whatIsThisCharacter)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whatIsThisCharacter > 16 ? CWHITE : CBLACK);
	PrintKing(x,y);

}

int main()
{
	Setting();
	for (int i = 1; i <= 8; i++)
			DrawCharacter(i, 2, 1);
	for (int i = 1; i <= 8; i++)
		DrawCharacter(i, 7, 19);
	Sleep(100000);
}