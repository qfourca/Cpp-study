#include <stdio.h>
float find(float *array)
{
    float max = 0;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int main()
{
    float arr[8];

    float max;
    int i;
    for (i = 0; i < 8; i++)
    {
        scanf("%f", &arr[i]);
    }
    max = find(arr);
    printf("%.1f", max);
    return 0;
}