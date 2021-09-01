#include <stdio.h>
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{
    int a = 5;
    int b = 7;
    printf("a = %d b = %d\n", a, b);
    swap(a, b);
    printf("a = %d b = %d\n", a, b);
    swap2(&a, &b);
    printf("a = %d b = %d\n", a, b);
    return 0;
}