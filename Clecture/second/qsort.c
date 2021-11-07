#include <stdio.h>
int n = 10;
int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quicksort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = left;
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (arr[i] <= arr[pivot])
            i++;
        while (arr[j] >= arr[pivot] && j > left)
            j--;

        if (i > j)
            swap(&arr[j], &arr[pivot]);
        else
            swap(&arr[i], &arr[j]);
    }
    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
}
int main()
{
    quicksort(array, 0, n - 1);
    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);

    //퀵 정렬 시간복잡도 O(NlogN)
}