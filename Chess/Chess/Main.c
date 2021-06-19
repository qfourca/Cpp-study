#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"


int main()
{
	Setting();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			DrawCharacter(i+1, j+1, Character[i][j]); // 캐릭터를 그리는 사람
	
	myCursor.x = 1;
	myCursor.y = 2;
	DrawBorder(myCursor.x, myCursor.y, RED);
	for (;;)
	{
		if (GetAsyncKeyState(VK_LEFT) && myCursor.x > 1)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(--myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_RIGHT) && myCursor.x < 8)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(++myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_UP) && myCursor.y < 8)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(myCursor.x, ++myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_DOWN) && myCursor.y > 1)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(myCursor.x, --myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_SPACE) && Character[myCursor.x-1][myCursor.y-1] != -1)
		{
			DrawBorder(myCursor.x, myCursor.y, AQUA);
			CanIGo(myCursor.x, myCursor.y);
			CharacterMovement(myCursor.x, myCursor.y);
			DrawBorder(myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
	}
}