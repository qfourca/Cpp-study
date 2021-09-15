#include <stdio.h>

int queue[5];
void menu()
{
    printf("\n-------------------------------------------------------\n");
    printf("1번 큐에 삽입 2번 큐에서 삭제\n");
    printf("3번 내용 보기(dispaly) 4번 종료(exit)");
    printf("\n-------------------------------------------------------\n");
}
void Enqueue(int *back, int item)
{
    if (*back == 4)
    {
        printf("큐가 가득 참\n");
    }
    queue[++*back] = item;
}
void Dequeue(int *front, int back)
{
    if (*front == back)
    {
        return -1;
    }
}
int main()
{
}