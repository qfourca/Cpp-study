#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct Game
{
	char name[20]; //캐릭터 이름
	char weapon[20]; //캐릭터의 무기 이름
	int power;
}myGame;
int main()
{
	myGame user;
	printf("캐릭터명 입력: ");
	scanf("%s", &user.name);
	printf("무기명 입력: ");
	scanf("%s", &user.weapon);
	printf("능력치 입력: ");
	scanf("%d", &user.power);
	printf("=====캐릭터 정보 출력=====\n캐릭터명: %s\n무기명: %s\n능력치: %d\n",user.name,user.weapon,user.power);

	return 0;

}