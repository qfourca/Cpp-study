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
	cout << "1. 계좌개설\n";
	cout << "2. 입    금\n";
	cout << "3. 출    금\n";
	cout << "4. 전체고객 잔액조회\n";
	cout << "5. 프로그램 종료\n";
	cout << "입력: ";
	std::cin >> a;
	return a;
}

void make(void)

{
	using namespace std;
	cout << "계좌번호를 입력 해 주세요: ";
	cin >> arr[accNum].accId;
	cout << "이름을 입력 해 주세요: ";
	cin >> arr[accNum].name;
	accNum++;
}

void input(void)
{
	using namespace std;
	int inMoney;
	int num;
	cout << "계좌번호를 입력 해 주세요: ";
	cin >> num;
	if (checkAccNum(num) == -1)
	{
		cout << "존재하지 않는 계좌번호 입니다" << "\n";
		return;
	}
	else
		num = checkAccNum(num);
	cout << "입금할 금액을 입력 해 주세요: ";
	cin >> inMoney;
	arr[num].money += inMoney;
	cout << inMoney << "원이 입금되었습니다" << "\n";
	cout << arr[num].name << "님의 ";
	cout << "잔액은 " << arr[num].money << "원입니다" << "\n";
}
void output(void)
{
	using namespace std;
	int outMoney;
	int num;
	cout << "계좌번호를 입력 해 주세요: ";
	cin >> num;
	if (checkAccNum(num) == -1)
	{
		cout << "존재하지 않는 계좌번호 입니다" << "\n";
		return;
	}
	else
		num = checkAccNum(num);
	cout << "출금할 금액을 입력 해 주세요: ";
	cin >> outMoney;
	if (checkAccMoney(outMoney, num) == -1)
	{
		cout << "잔액이 부족합니다" << "\n";
		return;
	}
	else
	{
		arr[num].money -= outMoney;
		cout << outMoney << "원이 출금되었습니다" << "\n";
		cout << arr[num].name << "님의 ";
		cout << "잔액은 " << arr[num].money << "원입니다" << "\n";
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
		std::cout << "이름: " << arr[i].name << "\n";
		std::cout << "잔액: " << arr[i].money << "\n\n";
	}
}

