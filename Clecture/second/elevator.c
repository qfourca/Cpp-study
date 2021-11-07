#include <stdio.h>
#include <stdlib.h>
int solution(int *floor, int len)
{
    int ret = 0;
    for (int i = 0; i < len - 1; i++)
    {
        ret += abs((*floor - *(floor + 1)));
        floor++;
    }
    return ret;
}
int main()
{
    int arr[128];
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("%d", solution(arr, size));
}
