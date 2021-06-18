#pragma once
#include "Header.h"
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