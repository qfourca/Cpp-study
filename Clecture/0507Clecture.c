#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	/*
	int N = 0;
	scanf("%d", &N);
	if (N == 1)
		printf("*");
	for(int i = 0;i<N;i++)
		printf("*");
	printf("\n");
	for (int i = 0; i < N-2; i++)
	{
		printf("*");
		for (int j = 0; j < N-2; j++)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < N; i++)
		printf("*");
	*/

	int arr[3] = { 0 };
	int t, x = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++){
			scanf("%d", &t);
			arr[i] += t;
		}
	for (int i = 0; i < 3; i++)
		if (((double)arr[i] / 4) >= 80.0){
			printf("pass\n");
			x++;
		}
		else
			printf("fail\n");
	printf("гу╟щ : %d", x);
	return 0;
}