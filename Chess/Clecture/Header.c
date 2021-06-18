#include "Header.h"
void gotoxy(int x, int y)
{
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서의 위치를 정해주는 함수
}

void Setting()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	system("mode con cols=500 lines=135");

	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			drawWin[i][j] = true;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			isColor[i][j] = true;

	for (int i = 0; i < 8; i += 2)
		for (int j = 1; j < 8; j += 2)
			isColor[i][j] = false;

	for (int i = 1; i < 8; i += 2)
		for (int j = 0; j < 8; j += 2)
			isColor[i][j] = false;

	for (int i = 0; i <= 120; i += 15)
		PutHorizontal(60, 180, i);
	for (int i = 60; i <= 180; i += 15)
		PutVertical(0, 120, i);
	drawWin[180][120] = false;

	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			drawWin[j][i] ? SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240) : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			printf("%s", fullpoint);
		}
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			DrawCore(i, j, isColor[i - 1][j - 1]);

	
}

int ReturnX(int x)
{
	switch (x)
	{
	case a: return 61; break;
	case b: return 76; break;
	case c: return 91; break;
	case d: return 106; break;
	case e: return 121; break;
	case f: return 136; break;
	case g: return 151; break;
	case h: return 166; break;
	default: return -1;
	}
}

int ReturnY(int y)
{
	switch (y)
	{
	case 8: return 1; break;
	case 7: return 16; break;
	case 6: return 31; break;
	case 5: return 46; break;
	case 4: return 61; break;
	case 3: return 76; break;
	case 2: return 91; break;
	case 1: return 106; break;
	default: return -1;
	}
}

void PutHorizontal(int Start, int End, int Ver)
{
	for (int i = Start; i < End; i++)
		drawWin[i][Ver] = false;
}

void PutVertical(int Start, int End, int Hor)
{
	for (int i = Start; i < End; i++)
		drawWin[Hor][i] = false;
}

void DrawCore(char x, int y, bool isWhite)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), isWhite ? WWHITE : WBLACK);
	gotoxy(ReturnX(x), ReturnY(y));
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
			printf("%s", fullpoint);
		gotoxy(ReturnX(x), ReturnY(y) + i);
	}
}