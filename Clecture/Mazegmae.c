#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int maze[9][9] = { 
	{2,2,2,2,2,2,2,2,2},
	{2,0,0,0,0,0,0,0,2},
	{2,0,2,2,0,2,2,0,2},
	{2,0,2,0,0,2,0,0,2},
	{2,0,2,0,2,0,2,0,2},
	{2,0,0,0,0,0,2,0,2},
	{2,2,0,2,2,0,2,2,2},
	{2,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2} };
int si, sj, ei, ej, sucess, sp, ri[100], rj[100];
int visit(int, int);
int main()
{
	printf("미로 탐색하기\n");
	si = 1, sj = 1, ei = 7, ej = 7; //출발점 (1,1) 도착점 (7,7)
	if (visit(si, sj) == 0)
		printf("출구를 찾을 수 없음");
	else
		printf("\n");
	return 0;
}
int visit(int i, int j)
{
	int k;
	static int path = 1;
	maze[i][j] = 1;
	ri[sp] = 1, rj[sp] = j;//지나간 행과 열 번호 저장
	sp++;
	if (i == ei && j == ej)
	{ //도착점에 도착했다면
		printf("찾은 길(%d)", path++);
		for (k = 0; k < sp; k++)
			printf("(%d,%d)", ri[k], rj[k]);
		printf("\n");
		sucess = 1;
	}
	////////////////////미로탐색로직///////////////////////
	if (maze[i][j + 1] == 0) //오른
		visit(i, j + 1);
	if (maze[i + 1][j] == 0) //아래
		visit(i + 1, j);
	if (maze[i][j - 1] == 0) //왼쪽
		visit(i, j - 1);
	if (maze[i - 1][j] == 0) //위쪽
		visit(i - 1, j);
	sp--;
	maze[i][j] = 0;
	return sucess;
}