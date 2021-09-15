#define MOUNTAIN 12000
#include <stdio.h>
int main()
{
    int thous;
    int ten;
    int time;
    scanf("%d %d %d", &thous, &ten, &time);

    int ans = 1;

    char array[MOUNTAIN + 1];
    for (int i = 0; i < MOUNTAIN + 1; i++)
        array[i] = 0;
    array[0] = 1;

    int start = 1;
    for (;;)
    {
        for (int j = 0; j < ten; j++)
        {
            if (start + j == time)
            {
                printf("%d", ans);
                return 1;
            }
            ans++;
            array[start + j] = 1;
        }
        start += thous;
        if (start > MOUNTAIN)
        {
            for (int i = 1; i < MOUNTAIN; i++)
                if (array[i] == 0)
                {
                    start = i;
                    break;
                }
        }
    }
    printf("%d", ans);
}