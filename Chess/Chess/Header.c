#include "Header.h"


bool ReturnColor(int x, int y) { return Character[x][y] < 15 ? true : false; }
bool OverSize(int a, int b) { return a >= 0 && a <= 7 && b >= 0 && b <= 7; }

void gotoxy(int x, int y)
{
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서의 위치를 정해주는 함수
}

int Setting()
{
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time

	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font.dwFontSize.X = 6;
	font.dwFontSize.Y = 12;
	SetCurrentConsoleFontEx(outcon, false, &font);
	SetConsoleTextAttribute(outcon, 0x05);
	SetConsoleTitle(TEXT("와! 신난다! 즐거운 체스게임"));
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	system("mode con cols=500 lines=135");
	//////////서버 통신////////////
	
	//////////////연결후//////////////

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

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			Character[j][i] = -1;

	Character[0][0] = 4;
	Character[7][0] = 4;
	Character[1][0] = 3;
	Character[6][0] = 3;
	Character[2][0] = 2;
	Character[5][0] = 2;
	Character[3][0] = 5;
	Character[4][0] = 6;
	for (int i = 0; i < 8; i++)
		Character[i][1] = 1;

	Character[0][7] = 64;
	Character[7][7] = 64;
	Character[1][7] = 48;
	Character[6][7] = 48;
	Character[2][7] = 32;
	Character[5][7] = 32;
	Character[3][7] = 80;
	Character[4][7] = 96;
	for (int i = 0; i < 8; i++)
		Character[i][6] = 16;
	Cursor myCursor;
	myCursor.x = 1;
	myCursor.y = 2;
	return 0;
}

void CanIGo(int x, int y)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			canIGo[i][j] = (bool)false;
	switch (Character[x - 1][y - 1])
	{
	case 1:
	case 16: CanIGoPon(x, y); break;
	case 2:
	case 32: CanIGoBishop(x, y); break;
	case 3:
	case 48: CanIGoKnight(x, y); break;
	case 4:
	case 64: CanIGoRook(x, y); break;
	case 5:
	case 80: CanIGoQueen(x, y); break;
	case 6:
	case 96: CanIGoKing(x, y); break;
	default: break;
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (canIGo[i][j] == true) { DrawBorder(i + 1, j + 1, GREEN); }

}

void DrawBorder(int x, int y, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	gotoxy(ReturnX(x), ReturnY(y));
	printf("                            ");
	gotoxy(ReturnX(x), ReturnY(y) + 13);
	printf("                            ");
	for (int i = ReturnY(y) + 1; i <= ReturnY(y) + 12; i++)
	{
		gotoxy(ReturnX(x), i);
		printf("%s", fullpoint);
		gotoxy(ReturnX(x) + 13, i);
		printf("%s", fullpoint);
	}

}
int CharacterMovement(int x, int y)
{
	int FirstX = x, FirstY = y;

	Sleep(AFTERINPUTKEYSTOP*2);
	for (;;)
	{
		if (GetAsyncKeyState(VK_LEFT ) && myCursor.x > 1)
		{
			DrawBorder(x, y, canIGo[x - 1][y - 1] ? GREEN : isColor[x - 1][y - 1] ? WWHITE : WBLACK);
			DrawBorder(--x, y, canIGo[x - 2][y - 1]?AQUA:RED);
			myCursor.x--;
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_RIGHT ) && myCursor.x < 8)
		{
			DrawBorder(x, y, canIGo[x - 1][y - 1] ? GREEN : isColor[x - 1][y - 1] ? WWHITE : WBLACK);
			DrawBorder(++x, y, canIGo[x][y - 1] ? AQUA : RED);
			myCursor.x++;
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_UP ) && myCursor.y < 8)
		{
			DrawBorder(x, y, canIGo[x - 1][y - 1] ? GREEN : isColor[x - 1][y - 1] ? WWHITE : WBLACK);
			DrawBorder(x, ++y, canIGo[x - 1][y] ? AQUA : RED);
			myCursor.y++;
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_DOWN ) && myCursor.y > 1)
		{
			DrawBorder(x, y, canIGo[x - 1][y - 1] ? GREEN : isColor[x - 1][y - 1] ? WWHITE : WBLACK);
			DrawBorder(x, --y, canIGo[x - 1][y - 2] ? AQUA : RED);
			myCursor.y--;
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_SPACE) && canIGo[x-1][y-1] == true && ((turnCount % 2 == 0 ) != myColorIsWhite))
		{
			DrawCore(FirstX, FirstY, isColor[FirstX - 1][FirstY - 1]);
			DrawCore(x, y, isColor[x - 1][y - 1]);
			DrawCharacter(x, y, Character[x - 1][y - 1]);
			RemoveAllBorder();
			return FirstX * 1000 + FirstY * 100 + x * 10 + y;
		}
		if (GetAsyncKeyState(VK_BACK)) 
		{
			RemoveAllBorder();
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					canIGo[i][j] = false;
			DrawBorder(myCursor.x, myCursor.y, RED);
			return 1;
		}
	}
	return -1;
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


void RemoveAllBorder()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			DrawBorder(i + 1, j + 1, isColor[i][j] ? WWHITE : WBLACK);
}



/////////////////////////////////////////////////
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
int ReturnX(int x)
{
	switch (x)
	{
	case 1: return 61; break;
	case 2: return 76; break;
	case 3: return 91; break;
	case 4: return 106; break;
	case 5: return 121; break;
	case 6: return 136; break;
	case 7: return 151; break;
	case 8: return 166; break;
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


void CanIGoPon(int x, int y)
{
	x--; y--;
	bool isWhite = Character[x][y] < 15;
	if (isWhite)
	{
		if (Character[x][y + 1] == -1) { canIGo[x][y + 1] = true; }
		if (Character[x][y + 2] == -1 && y == 1 && canIGo[x][y + 1] == true) { canIGo[x][y + 2] = true; }
		if (Character[x + 1][y + 1] != -1 && ReturnColor(x + 1, y + 1) != isWhite) { canIGo[x + 1][y + 1] = true; }
		if (Character[x - 1][y + 1] != -1 && ReturnColor(x - 1, y + 1) != isWhite) { canIGo[x - 1][y + 1] = true; }
	}
	else
	{
		if (Character[x][y - 1] == -1) { canIGo[x][y - 1] = true; }
		if (Character[x][y - 2] == -1 && y == 6 && canIGo[x][y - 1] == true) { canIGo[x][y - 2] = true; }
		if (Character[x + 1][y - 1] != -1 && ReturnColor(x + 1, y - 1) != isWhite) { canIGo[x + 1][y - 1] = true; }
		if (Character[x - 1][y - 1] != -1 && ReturnColor(x - 1, y - 1) != isWhite) { canIGo[x - 1][y - 1] = true; }
	}
}
void CanIGoBishop(int x, int y)
{
	int firstX = x, firstY = y;
	bool isWhite = Character[x - 1][y - 1] < 15;
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x++; y++;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x--; y++;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x++; y--;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x--; y--;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
}
void CanIGoKnight(int x, int y)
{
	x--; y--;
	bool isWhite = Character[x][y] < 15;
	if (OverSize(x + 2, y + 1) && (Character[x + 2][y + 1] == -1 || ReturnColor(x + 2, y + 1) != isWhite)) { canIGo[x + 2][y + 1] = true; }
	if (OverSize(x + 2, y - 1) && (Character[x + 2][y - 1] == -1 || ReturnColor(x + 2, y - 1) != isWhite)) { canIGo[x + 2][y - 1] = true; }
	if (OverSize(x - 2, y + 1) && (Character[x - 2][y + 1] == -1 || ReturnColor(x - 2, y + 1) != isWhite)) { canIGo[x - 2][y + 1] = true; }
	if (OverSize(x - 2, y - 1) && (Character[x - 2][y - 1] == -1 || ReturnColor(x - 2, y - 1) != isWhite)) { canIGo[x - 2][y - 1] = true; }
	if (OverSize(x + 1, y + 2) && (Character[x + 1][y + 2] == -1 || ReturnColor(x + 1, y + 2) != isWhite)) { canIGo[x + 1][y + 2] = true; }
	if (OverSize(x + 1, y - 2) && (Character[x + 1][y - 2] == -1 || ReturnColor(x + 1, y - 2) != isWhite)) { canIGo[x + 1][y - 2] = true; }
	if (OverSize(x - 1, y + 2) && (Character[x - 1][y + 2] == -1 || ReturnColor(x - 1, y + 2) != isWhite)) { canIGo[x - 1][y + 2] = true; }
	if (OverSize(x - 1, y - 2) && (Character[x - 1][y - 2] == -1 || ReturnColor(x - 1, y - 2) != isWhite)) { canIGo[x - 1][y - 2] = true; }
}

void CanIGoRook(int x, int y)
{
	int firstX = x, firstY = y;
	bool isWhite = Character[x - 1][y - 1] < 15;
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x++;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		x--;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		y++;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
	for (x = firstX - 1, y = firstY - 1;;)
	{
		y--;
		if (!OverSize(x, y)) { break; }
		if (Character[x][y] == -1)
			canIGo[x][y] = true;
		else if (ReturnColor(x, y) != isWhite)
		{
			canIGo[x][y] = true;
			break;
		}
		else
			break;
	}
}
void CanIGoQueen(int x, int y)
{
	CanIGoBishop(x, y);
	CanIGoRook(x, y);
}

void CanIGoKing(int x, int y)
{
	x--; y--;
	bool isWhite = Character[x][y] < 15;
	if (OverSize(x + 1, y + 1) && (Character[x + 1][y + 1] == -1 || ReturnColor(x + 1, y + 1) != isWhite)) { canIGo[x + 1][y + 1] = true; }
	if (OverSize(x + 1, y) && (Character[x + 1][y] == -1 || ReturnColor(x + 1, y) != isWhite)) { canIGo[x + 1][y] = true; }
	if (OverSize(x + 1, y - 1) && (Character[x + 1][y - 1] == -1 || ReturnColor(x + 1, y - 1) != isWhite)) { canIGo[x + 1][y - 1] = true; }
	if (OverSize(x, y + 1) && (Character[x][y + 1] == -1 || ReturnColor(x, y + 1) != isWhite)) { canIGo[x][y + 1] = true; }
	if (OverSize(x, y - 1) && (Character[x][y - 1] == -1 || ReturnColor(x, y - 1) != isWhite)) { canIGo[x][y - 1] = true; }
	if (OverSize(x - 1, y + 1) && (Character[x - 1][y + 1] == -1 || ReturnColor(x - 1, y + 1) != isWhite)) { canIGo[x - 1][y + 1] = true; }
	if (OverSize(x - 1, y) && (Character[x - 1][y] == -1 || ReturnColor(x - 1, y) != isWhite)) { canIGo[x - 1][y] = true; }
	if (OverSize(x - 1, y - 1) && (Character[x - 1][y - 1] == -1 || ReturnColor(x - 1, y - 1) != isWhite)) { canIGo[x - 1][y - 1] = true; }
}


void PrintPon(int x, int y)
{
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 1);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 2);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 3);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 4);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 5);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 6);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 7);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 8);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 4, ReturnY(y) + 9);
	for (int i = 0; i < 7; i++) { printf("%s", fullpoint); }
}
void PrintBishop(int x, int y)
{
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 1);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 2);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 3);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 4);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 8, ReturnY(y) + 4);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 5);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 5);
	printf("%s", fullpoint);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 6);
	for (int i = 0; i < 4; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 7);
	for (int i = 0; i < 4; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 8);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 9);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 10);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 4, ReturnY(y) + 11);
	for (int i = 0; i < 6; i++) { printf("%s", fullpoint); }
}

void PrintKnight(int x, int y)
{
	gotoxy(ReturnX(x) + 4, ReturnY(y) + 1);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 4, ReturnY(y) + 2);
	for (int i = 0; i < 6; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 3);
	for (int i = 0; i < 8; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 2, ReturnY(y) + 4);
	for (int i = 0; i < 4; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 4);
	for (int i = 0; i < 4; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 2, ReturnY(y) + 5);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 9, ReturnY(y) + 5);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 8, ReturnY(y) + 6);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 7);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 8);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 9);
	for (int i = 0; i < 7; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 10);
	for (int i = 0; i < 8; i++) { printf("%s", fullpoint); }
}

void PrintRook(int x, int y)
{
	for (int i = 3; i < 10; i += 2) { gotoxy(ReturnX(x) + i, ReturnY(y) + 2);	printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 3);
	for (int i = 0; i < 7; i++) { printf("%s", fullpoint); }
	for (int i = 4; i < 10; i++) { gotoxy(ReturnX(x) + 4, ReturnY(y) + i);	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); } }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 10);
	for (int i = 0; i < 7; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 2, ReturnY(y) + 11);
	for (int i = 0; i < 9; i++) { printf("%s", fullpoint); }
}

void PrintQueen(int x, int y)
{
	gotoxy(ReturnX(x) + 7, ReturnY(y) + 2);
	printf("%s", fullpoint);
	for (int i = 4; i < 12; i += 3) { gotoxy(ReturnX(x) + i, ReturnY(y) + 4);	printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 5);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 6);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 7);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 8);
	for (int i = 0; i < 9; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 9);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 10);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 11);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 12);
	for (int i = 0; i < 5; i++) { printf("%s", fullpoint); }
}

void PrintKing(int x, int y)
{
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 3);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 1, ReturnY(y) + 4);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 4);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 11, ReturnY(y) + 4);
	printf("%s", fullpoint);
	gotoxy(ReturnX(x) + 1, ReturnY(y) + 5);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 5);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 10, ReturnY(y) + 5);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 2, ReturnY(y) + 6);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 5, ReturnY(y) + 6);
	for (int i = 0; i < 3; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 9, ReturnY(y) + 6);
	for (int i = 0; i < 2; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 3, ReturnY(y) + 7);
	for (int i = 0; i < 7; i++) { printf("%s", fullpoint); }
	gotoxy(ReturnX(x) + 4, ReturnY(y) + 8);
	for (int i = 0; i < 6; i++) { printf("%s", fullpoint); }
}
void PrintVoid(int x, int y)
{
	gotoxy(ReturnX(x) + 6, ReturnY(y) + 3);
}

void DrawCharacter(int x, int y, char whatIsThisCharacter)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), whatIsThisCharacter > 15 ? CWHITE : CBLACK);
	switch (whatIsThisCharacter)
	{
	case 1:
	case 16: PrintPon(x, y); break;
	case 2:
	case 32: PrintBishop(x, y); break;
	case 3:
	case 48: PrintKnight(x, y); break;
	case 4:
	case 64: PrintRook(x, y); break;
	case 5:
	case 80: PrintQueen(x, y); break;
	case 6:
	case 96:PrintKing(x, y); break;
	case -1: DrawCore(x, y , isColor[x-1][y-1]);

	default: break;
	}
}
