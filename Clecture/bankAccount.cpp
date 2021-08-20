#include <iostream>

int start(void);
void make(void);
void input(void);
void output(void);
void print(void);
int checkAccNum(int);
int checkAccMoney(int, int);

enum
{
	Make = 1, Input, Output, Print, End
};

struct account
{
	int accId;
	int money;
	char name[20];
};

account arr[100];
int accNum = 0;

int main(void)
{
	for (;;)
	{
		int begin = start();
		switch (begin)
		{
		case Make: make(); break;
		case Input: input(); break;
		case Output: output(); break;
		case Print: print(); break;
		case End: return 0;
		}
	}

	return 0;
}
int start(void)
{
	int a;
	using std::cout;
	cout << "1. ���°���\n";
	cout << "2. ��    ��\n";
	cout << "3. ��    ��\n";
	cout << "4. ��ü�� �ܾ���ȸ\n";
	cout << "5. ���α׷� ����\n";
	cout << "�Է�: ";
	std::cin >> a;
	return a;
}

void make(void)

{
	using namespace std;
	cout << "���¹�ȣ�� �Է� �� �ּ���: ";
	cin >> arr[accNum].accId;
	cout << "�̸��� �Է� �� �ּ���: ";
	cin >> arr[accNum].name;
	accNum++;
}

void input(void)
{
	using namespace std;
	int inMoney;
	int num;
	cout << "���¹�ȣ�� �Է� �� �ּ���: ";
	cin >> num;
	if (checkAccNum(num) == -1)
	{
		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�" << "\n";
		return;
	}
	else
		num = checkAccNum(num);
	cout << "�Ա��� �ݾ��� �Է� �� �ּ���: ";
	cin >> inMoney;
	arr[num].money += inMoney;
	cout << inMoney << "���� �ԱݵǾ����ϴ�" << "\n";
	cout << arr[num].name << "���� ";
	cout << "�ܾ��� " << arr[num].money << "���Դϴ�" << "\n";
}
void output(void)
{
	using namespace std;
	int outMoney;
	int num;
	cout << "���¹�ȣ�� �Է� �� �ּ���: ";
	cin >> num;
	if (checkAccNum(num) == -1)
	{
		cout << "�������� �ʴ� ���¹�ȣ �Դϴ�" << "\n";
		return;
	}
	else
		num = checkAccNum(num);
	cout << "����� �ݾ��� �Է� �� �ּ���: ";
	cin >> outMoney;
	if (checkAccMoney(outMoney, num) == -1)
	{
		cout << "�ܾ��� �����մϴ�" << "\n";
		return;
	}
	else
	{
		arr[num].money -= outMoney;
		cout << outMoney << "���� ��ݵǾ����ϴ�" << "\n";
		cout << arr[num].name << "���� ";
		cout << "�ܾ��� " << arr[num].money << "���Դϴ�" << "\n";
	}
}
int checkAccNum(int accIden)
{
	for (int i = 0; i < accNum; i++)
	{
		if (accIden == arr[i].accId)
		{
			return i;
		}
	}
	return -1;
}
int checkAccMoney(int Inmoney, int accIden)
{
	if (arr[accIden].money < Inmoney)
		return -1;
	else
		return 0;
}

void print(void)
{
	for (int i = 0; i < accNum; i++)
	{
		std::cout << "�̸�: " << arr[i].name << "\n";
		std::cout << "�ܾ�: " << arr[i].money << "\n\n";
	}
}


