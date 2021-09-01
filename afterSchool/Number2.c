#include <stdio.h>
void geometric()
{
    static int count = 1;
    printf("%d ", count * 2);
    count *= 2;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        geometric();
    }
}