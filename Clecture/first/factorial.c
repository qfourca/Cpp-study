#include <stdio.h>
int factorial(int input)
{
    return ((input == 0) ? 1 : input * factorial(input - 1));
}

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("factorial %d : %d\n", i, factorial(i));
    }
    return 0;
}