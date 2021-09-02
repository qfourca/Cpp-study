#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int MySort(int n1, int n2)
{
    return n1 > n2;
}
int main()
{
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, MySort);
    LInsert(&list, 1);
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 1);
    LInsert(&list, 7);
    LInsert(&list, 6);
    printf("현재 데이터의 수 %d \n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d", data);
        while (LNext(&list, &data))
        {
            printf("%d", data);
        }
    }
    if (LFirst(&list, &data))
    {
        if (data == 2)
            LRemove(&list);
        while (LNext(&list, &data))
        {
            if (data == 2)
                LRemove(&list);
        }
    }
    printf("\n현재 데이터의 수 %d \n", LCount(&list));
    printf("\n\n");
}