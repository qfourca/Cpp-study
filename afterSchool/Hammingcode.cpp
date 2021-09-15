#include <stdio.h>
char array[8] = {1, 1, 0, 1, 0, 0, 1, 0};
//짝수 - true
char isHammingOK()
{
    char error1 = array[1];
    char error2 = array[2];
    char error3 = array[4];
    for (int i = 2; i < 8; i++)
        if (array[i])
            !error1;

    for (int i = 3; i < 8; i++)
        if (array[i])
            !error2;

    for (int i = 5; i < 8; i++)
        if (array[i])
            !error3;

    printf("%d %d %d\n", error1, error2, error3);
    return error1 + (error2 << 2) + (error3 << 3);
}
int main()
{
    printf("%d", isHammingOK());
}