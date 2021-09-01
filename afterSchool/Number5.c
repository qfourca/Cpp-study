#include <stdio.h>
void cat(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        str1++;
    }
    *str1 = ' ';
    while (*str2 != '\0')
    {
        str1++;
        *str1 = *str2;

        str2++;
    }
    str1++;
    *str1 = '\0';
}
int main()
{
    char h1[50];
    char h2[50];

    scanf("%s", h1);
    scanf("%s", h2);
    cat(h1, h2);
    printf("%s\n", h1);
}