#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int* arr, int len)
{
	int temp;
	for(int i = 0;i<len-1;i++)
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1]) // 불필요한 검사 제거
			{
				temp = arr[j]; // 배열의 값을 바꾸는 코드
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main(void) 
{
	int arr[5] = { 4,6,1,3,9 };
	BubbleSort(arr, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]); // 정렬된 값 출력
	return 0;
}