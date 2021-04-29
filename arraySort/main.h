#pragma once

int typeInt(string input)
{
	
}

void gotoxy(int x, int y)
{
	COORD Pos; //x, y를 가지고 있는 구조체 
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}