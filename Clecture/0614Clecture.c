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
	printf("이름 입력 : ");
	scanf("%s", me.name);
	printf("나이 입력 : ");
	scanf("%d", &me.age);
	printf("번호 입력 : ");
	scanf("%d", &me.number);
	printf("제 이름은 %s, 나이는 %d 번호는 %d 입니다.", me.name, me.age, me.number);

}