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
	printf("�̷� Ž���ϱ�\n");
	si = 1, sj = 1, ei = 7, ej = 7; //����� (1,1) ������ (7,7)
	if (visit(si, sj) == 0)
		printf("�ⱸ�� ã�� �� ����");
	else
		printf("\n");
	return 0;
}
int visit(int i, int j)
{
	int k;
	static int path = 1;
	maze[i][j] = 1;
	ri[sp] = 1, rj[sp] = j;//������ ��� �� ��ȣ ����
	sp++;
	if (i == ei && j == ej)
	{ //�������� �����ߴٸ�
		printf("ã�� ��(%d)", path++);
		for (k = 0; k < sp; k++)
			printf("(%d,%d)", ri[k], rj[k]);
		printf("\n");
		sucess = 1;
	}
	////////////////////�̷�Ž������///////////////////////
	if (maze[i][j + 1] == 0) //����
		visit(i, j + 1);
	if (maze[i + 1][j] == 0) //�Ʒ�
		visit(i + 1, j);
	if (maze[i][j - 1] == 0) //����
		visit(i, j - 1);
	if (maze[i - 1][j] == 0) //����
		visit(i - 1, j);
	sp--;
	maze[i][j] = 0;
	return sucess;
}