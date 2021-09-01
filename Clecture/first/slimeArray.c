#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
int arr[SIZE][SIZE];

void makeArr(int n)
{
	int cnt = 1;
	int row = 0, col = -1;
	int inc = 1;
	for (; n > 0;)
	{
		for (int i = 0; i < n; i++)
		{
			col += inc;
			arr[row][col] = cnt++;
		}
		n--;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			row += inc;
			arr[row][col] = cnt++;
		}
		inc *= -1;
	}
}
void Print(int n) {
	int row = 0, col = -1;
	int inc = 1;
	for (; n > 0;)
	{
		for (int i = 0; i < n; i++)
		{
			col += inc;
			printf("%d\n", arr[row][col]);
		}
		n--;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			row += inc;
			printf("%d\n", arr[row][col]);
		} 
		inc *= -1;
	}
}

int main()
{
	int n = 0;
	printf("달팽이 배열의 길이 : ");
	scanf("%d", &n);
	makeArr(n);
	Print(n);

}