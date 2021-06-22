#pragma once
#define fullpoint "  "
#define GREY 112
#define BLACK 0
#define WHITE 240
#define HEIGHT 130
#define WIDTH 250
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void gotoxy(int x, int y)
{
	x *= 2;
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서의 위치를 정해주는 함수
}