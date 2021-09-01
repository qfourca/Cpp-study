//빅 오 시간복잡도
//O(1)
//O(log n)
//O(n)
//O(n log n)
//O(n^2)
//O(n^3)
//O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct stu Stu;

struct stu
{
    char name[10]; //각각의 변수를 멤버변수라고 부름
    int age;
    int score;
};

int main()
{
    Stu s1 = {"Kim", 17, 90};
    Stu s2 = {"Park", 17, 80};
    printf("%s %d %d\n", s1.name, s1.age, s1.score);
    printf("%s %d %d\n", s2.name, s2.age, s2.score);
    return 0;
}
*/
/*
typedef struct STU stu;
struct STU
{
    char name[10];
    int age;
};

int main()
{
    stu *student;
    student = (stu *)malloc(sizeof(stu));
    scanf("%s %d", student->name, &student->age);
    printf("%s %d\n", student->name, student->age);
    free(student);
}
*/
typedef struct NODE ND;
struct NODE
{
    ND *next;
    int data;
};
int main()
{
    ND *head = (ND *)malloc(sizeof(ND));
    ND *node1 = (ND *)malloc(sizeof(ND));
    head->next = node1;
    node1->data = 10;
}
