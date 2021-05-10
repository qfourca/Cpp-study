#pragma once
#include <Windows.h>
#include <iostream>

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear(int x, int y)
{
	for (int i = 0; i < x + 1; i++)
	{
		gotoxy(x + 1, i);
		std::cout << "�̢�\n";
	}
}
