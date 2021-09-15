#include <stdio.h>
#define STACKSIZE 5;

int stack[5];
void push(int); //스택에 데이터 한개 삽입
void pop();     //스택에 데이터 한개 빼기
void display();
void menu();
int top = -1;

int main()
{
    int val, n;
    printf("**********스택 구현 메뉴******************");
    while (1)
    {
        menu();
        printf("메뉴를 선택하세요 : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1: //push
            printf("스택에 삽입할 숫자 ");
            scanf("%d", &n);
            push(n);
            break;
        case 2: //pop
            pop();
            break;
        case 3: //display
            display();
            break;
        case 4: //exit
            return 0;
            break;
        default:
            printf("다시 입력 하세요");
        }
    }
}
void menu()
{
    printf("\n-------------------------------------------------------\n");
    printf("1번 스택에 삽입(push) 2번 스택에서 삭제(pop)\n");
    printf("3번 내용 보기(dispaly) 4번 프로그램 종료(exit)");
    printf("\n-------------------------------------------------------\n");
}

void push(int arg)
{
    if (top >= 4)
        printf("스택이 가득참");
    else
        stack[++top] = arg;
}
void pop()
{
    if (top == -1)
        printf("스택이 비었음\n");
    else
        printf("%d가 삭제됨\n", stack[top--]);
}
void display()
{
    printf("---------------\n");
    for (int i = 0; i <= top; i++)
        printf("%4d", stack[i]);
    printf("\n---------------\n");
};