#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct data Student;
struct data
{
	char name[20];
	int age;
	int number
};
int main()
{
	Student me;
	printf("�̸� �Է� : ");
	scanf("%s", me.name);
	printf("���� �Է� : ");
	scanf("%d", &me.age);
	printf("��ȣ �Է� : ");
	scanf("%d", &me.number);
	printf("�� �̸��� %s, ���̴� %d ��ȣ�� %d �Դϴ�.", me.name, me.age, me.number);

}