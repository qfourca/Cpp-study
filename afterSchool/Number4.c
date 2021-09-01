#include <stdio.h>
#include <string.h>
int main(void)
{
    char h1[50];
    char h2[50];

    fgets(h1, 50, stdin);
    fgets(h2, 50, stdin);

    /*for (int i = 0; i < 50; i++)
    {
        if (h1[i] == '\0' && h2[i] == '\0')
            break;
        if (h1[i] > h2[i])
        {
            printf("%s", h1);
            return 0;
        }
        else if (h1[i] < h2[i])
        {
            printf("%s", h2);
            return 0;
        }
    }*/
    char *p = h1;
    char *q = h2;
    while (*p != '\0' && *q != '\0')
    {
        p++;
        q++;
        if (*p > *q)
        {
            printf("h1 big");
            return 0;
        }
        else if (*p < *q)
        {
            printf("h2 big");
            return 0;
        }
    }
    printf("같다");
    return 0;
}