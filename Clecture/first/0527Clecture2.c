#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Student 
{
	char name[20];
	int stuNum;
	int age;
	char adress[100];
}student;
int main()
{
	student class12[20];

	for (int i = 0; i < 3; i++)
	{
		printf("이름 입력: ");
		scanf("%s", class12[i].name);
		scanf("%d", &class12[i].age);
		scanf("%d", &class12[i].stuNum);
		scanf(" %[^\n]", class12[i].adress);
	}
	strcpy(class12[0].name,"홍길동");
	class12[0].stuNum = 1201;
	class12[0].age = 17;
	strcpy(class12[0].adress, "대구 달성군");
	printf("====1-2 학생정보====\n");
	printf("이름: %s\n", class12[0].name);
	printf("나이: %d\n", class12[0].age);
	printf("학번: %d\n", class12[0].stuNum);
	printf("주소: %s\n", class12[0].adress);
	return 0;
}