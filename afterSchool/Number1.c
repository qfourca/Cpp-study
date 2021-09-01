#include <stdio.h>

int main()
{
    int i,j;

    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("기존 이차원 배열\n");
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j<3;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("행과 열을 바꾼 이차원 배열\n");
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j<3;j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
    return 0;
}