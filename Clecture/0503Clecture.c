#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	/*
	// 포인터란 주소를 저장하는 변수이다
	int* ptr1 = 1000;
	printf("%d\n", ptr1);
	printf("%d\n", ++ptr1); // 1증가란 int형 1바이트 증가를 의미
	*/
	/*
	int arr[5] = { 1,2,3,4,5 };
	int* pArr = arr;
	printf("%d \n", *pArr);
	printf("%d \n", *(++pArr));
	printf("%d \n", *(++pArr));
	printf("%d \n", *(pArr+1));
	printf("%d \n", *(pArr+2));
	*/
	/*
	char str1[10] = "abcd";
	char* str2 = "ABCD";
	printf("%s %s\n", str1, str2);
	str1[1] = 'x';
	str2[1] = 'x'; // 나 문제 있음
	printf("%s %s\n", str1, str2);
	*/

	/*
	char str[3][10] = { "kim","hong","chu" }; // 3은 행 10은 열
	char* pStr[3] = { str[0],str[1],str[2] };
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);

	//printf("%s\n", *pStr);
	//printf("%s\n", *(pStr + 1));

	printf("%c\n", str[0][0]);
	printf("%c\n", str[0][1]);
	printf("%c\n", str[0][2]);
	*/

	return 0;
}