#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include "main.h"
using namespace std;

int arr[105]{ 0 };
int number, delayTime;
string type;

void randomDataInput(int i);
void inPrint();

int main()
{
	for (;;)
	{
		inPrint();
		for(int i = 0;)
	}
	return 0;

}

void randomDataInput(int i)
{
	int t = ((rand() % number) + 1);
	for (int j = 0; j < i; j++)
	{
		if (arr[j] == t)
		{
			randomDataInput(i);
			return;
		}
	}
	arr[i] = t;
}


void inPrint()
{
	cout << "�������� ���� ���Ĺ�� �����ð� ������ �Է��� �ּ���";
	srand(static_cast<unsigned int>(time(NULL)));
	cin >> number >> type >> delayTime;
	system("cls");
	if (number < 2)
		cout << "�ʹ� ���� ���Դϴ�";
	else if (number >= 100)
		cout << "�ʹ� ū ���Դϴ�";
	else
		for (int i = 0; i < number; i++)
		{
			randomDataInput(i);
		}
	tablePrint();
	Sleep(1000);
}

void tablePrint()
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			gotoxy(i + 1, number + 5 - j);
			cout << "��";
		}
	}
}