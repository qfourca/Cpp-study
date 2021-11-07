#include <stdio.h>
#include <stdbool.h>
bool isSexyear(int input)
{
    bool ret;
    if (input % 4 == 0)
    {
        ret = true;
        if (input % 100 == 0)
        {
            ret = false;
            if (input % 400 == 0)
                ret = true;
        }
    }
}
int monBef(int input)
{
    int ret = 0;

    for (int i = 1; i < input; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            ret += 31;
        else if (i == 2)
            ret += 28;
        else
            ret += 30;
    }
}
int main()
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    int sexYear;
    for (int i = 1; i < year; i++)
    {
        if (isSexyear(i))
            sexYear++;
    }
    long long int days = 365 * year + sexYear - 365;
    days += monBef(month);
    days += day;
    if (month >= 3 && isSexyear(year))
        days++;

    days %= 7;
    switch (days % 7)
    {
    case 1:
        printf("MON\n");
        break;
    case 2:
        printf("TUE\n");
    case:
    }
}