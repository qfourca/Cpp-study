#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int* arr, int len)
{
	int temp;
	for(int i = 0;i<len-1;i++)
		for (int j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1]) // ���ʿ��� �˻� ����
			{
				temp = arr[j]; // �迭�� ���� �ٲٴ� �ڵ�
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

int main(void) 
{
	int arr[5] = { 4,6,1,3,9 };
	BubbleSort(arr, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]); // ���ĵ� �� ���
	return 0;
}