#pragma once

int typeInt(string input)
{
	
}

void gotoxy(int x, int y)
{
	COORD Pos; //x, y�� ������ �ִ� ����ü 
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}