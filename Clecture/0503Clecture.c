#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	/*
	// �����Ͷ� �ּҸ� �����ϴ� �����̴�
	int* ptr1 = 1000;
	printf("%d\n", ptr1);
	printf("%d\n", ++ptr1); // 1������ int�� 1����Ʈ ������ �ǹ�
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
	str2[1] = 'x'; // �� ���� ����
	printf("%s %s\n", str1, str2);
	*/

	/*
	char str[3][10] = { "kim","hong","chu" }; // 3�� �� 10�� ��
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