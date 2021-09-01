#include <stdio.h>
int main()
{
    int num;
    int ans = 1;
    scanf("%d", &num);
    while (num != 1)
    {
        if (num % 2 == 1)
        {
            num *= 3;
            num++;
        }
        else
        {
            num /= 2;
        }
        ans++;
    }
    printf("우박수의 길이는 %d이다\n", ans);
}