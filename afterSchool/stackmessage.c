#include <stdio.h>
int main()
{
    char array[1024];
    char charStack[1024];
    scanf("%s", array);
    int charStackIdx = 0;
    for (int i = 0; array[i] != 0; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
            for (char j = 0; j < array[i] - '0'; j++)
                printf("%c", charStack[--charStackIdx]);
        else
            charStack[charStackIdx++] = array[i];
    }
}
