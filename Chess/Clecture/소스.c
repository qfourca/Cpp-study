#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
enum HorChar { a = 1, b, c, d, e, f, g, h };
bool drawWin[WIDTH][HEIGHT];// x y

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
int ReturnX(char x)
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
	case h: return 165; break;
		default 
	}
}
int ReturnY(int y)
{
	switch (y)
	{
	case 1: return 61; break;
	case 2: return 76; break;
	case 3: return 91; break;
	case 4: return 106; break;
	case 5: return 121; break;
	case 6: return 136; break;
	case 7: return 151; break;
	case 8: return 165; break;
	}
}

void PutGrey(char x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREY);
	enum Hor hor = x;
	gotoxy(ReturnX(x), 1);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
			printf("%s", fullpoint);
		gotoxy(61, i + 1);
	}
}

int main()
{
	Setting();

	for (int i = 0; i <= 120; i += 15)
		PutHorizontal(60, 180, i);
	for (int i = 60; i <= 180; i += 15)
		PutVertical(0, 120, i);
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
		{
			drawWin[j][i] ? SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE) : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
			printf("%s", fullpoint);
		}
	PutGrey(b, 61);

	Sleep(100000);
}