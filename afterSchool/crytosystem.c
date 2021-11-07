#include <stdio.h>

int main()
{
    int key;
    char str[BUFSIZ];
    scanf("%d %s", &key, str);

    for (char *ptr = str; *ptr != 0; ptr++)
    {
        int befKey = key;
        key *= key;
        if (befKey <= 316)
            key %= 1000;
        else
            key %= 10000;

        if (((*ptr) + key / 100) > 90)
        {
            int t = ((*ptr) + (key / 100)) - 90;
            printf("%d\n", t);
            *ptr = 65 + t;
        }
        else
        {
            (*ptr) += key / 100;
        }
    }
    printf("%s\n", str);
}