#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include "main.h"
#define DELAY 1000
using namespace std;

int arr[105]{ 0 };
int number, delayTime;
string type;

void randomDataInput(int i);
void inPrint();
void tablePrint();
void tablePrintColor(int line);

int main()
{
	for (;;)
	{
		inPrint();
		for (int i = number - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
				tablePrintColor(j);
				Sleep(delayTime);
			}
		}
		textcolor(10, 0);
		tablePrint();
		Sleep(1000000);
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

void tablePrint()
{
	system("cls");
	for (int i = 0; i < number; i++)
	{
		gotoxy(i + 1, number + 5);
		cout << arr[i];
		for (int j = 1; j <= arr[i]; j++)
		{
			gotoxy(i + 1, number + 5 - j);
			cout << "��";
		}
	}
}

void inPrint()
{
	cout << "�������� ���� ���Ĺ�� �����ð� ������ �Է��� �ּ���" << endl;
	srand(static_cast<unsigned int>(time(NULL)));
	cin >> number >> type >> delayTime;
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
void tablePrintColor(int line)
{
	clear(line, number);
	for (int i = 0; i < number; i++)
	{
		if (i == line)
			textcolor(14, 0);
		else
			textcolor(15, 0);
		gotoxy(i + 1, number + 5);
		cout << arr[i];
		for (int j = 1; j <= arr[i]; j++)
		{
			gotoxy(i + 1, number + 5 - j);
			cout << "��";
		}
	}
}


