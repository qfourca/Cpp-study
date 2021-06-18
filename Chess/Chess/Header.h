#pragma once
#define fullpoint "  "

#define CWHITE 0 // 체스 캐릭터의 하얀색
#define WWHITE 128 // 체스 캐릭터의 검은색
#define WBLACK 112 // 체스 판의 검은색
#define CBLACK 240 // 체스 판의 검은색
#define BlUE 16
#define GREEN 32
#define AQUA 48
#define RED 64

#define HEIGHT 130
#define WIDTH 250 // 128
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


bool drawWin[WIDTH][HEIGHT];// x y
char Character[8][8];
bool isColor[8][8];

enum HorChar { a = 1, b, c, d, e, f, g, h };
void gotoxy(int x, int y);
void Setting();
int ReturnX(int x);
int ReturnY(int y);
void PutHorizontal(int Start, int End, int Ver);
void PutVertical(int Start, int End, int Hor);
void DrawCore(char x, int y, bool isWhite);
void PrintPon(int x, int y);
void PrintBishop(int x, int y);
void PrintKnight(int x, int y);
void PrintRook(int x, int y);
void PrintQueen(int x, int y);
void PrintKing(int x, int y);
void DrawCharacter(int x, int y, char whatIsThisCharacter);
void DrawBorder(int x, int y, int color);