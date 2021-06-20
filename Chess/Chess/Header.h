#pragma once
#define fullpoint "  "

#define AFTERINPUTKEYSTOP 100
#define CWHITE 0 // 체스 캐릭터의 하얀색
#define WWHITE 128 // 체스 캐릭터의 검은색
#define WBLACK 112 // 체스 판의 검은색
#define CBLACK 240 // 체스 판의 검은색
#define BLUE 48
#define GREEN 32
#define AQUA 16
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
bool canIGo[8][8];
bool myColorIsWhite;
int turnCount;
char serverInput[256];

typedef struct Cursor
{
	int x, y;
}Cursor;

Cursor myCursor;

enum HorChar { a = 1, b, c, d, e, f, g, h };
void gotoxy(int x, int y);
int Setting();
int ReturnX(int x);
int ReturnY(int y);
void RemoveAllBorder();
void PutHorizontal(int Start, int End, int Ver);
void PutVertical(int Start, int End, int Hor);
void DrawCore(char x, int y, bool isWhite);
void PrintPon(int x, int y);
void PrintBishop(int x, int y);
void PrintKnight(int x, int y);
void PrintRook(int x, int y);
void PrintQueen(int x, int y);
void PrintKing(int x, int y);
void PrintVoid(int x, int y);
void DrawCharacter(int x, int y, char whatIsThisCharacter);
void DrawBorder(int x, int y, int color);
void CanIGo(int x, int y);
void CanIGoPon(int x, int y);
void CanIGoBishop(int x, int y);
void CanIGoKnight(int x, int y);
void CanIGoRook(int x, int y);
void CanIGoQueen(int x, int y);
void CanIGoKing(int x, int y);
int CharacterMovement(int x, int y);


//bool isCharacterNotExist(int x, int y);
//void MoveCursor(int x,int y);