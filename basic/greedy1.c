#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    int coin[4] = { 500,100,50,10 };
    int num;
    int i;
    scanf("%d", &n);

    for (i = 0; i < 4; i++) {
        while (n >= coin[i]) {
            n -= coin[i];
            num++;
        }
    }
    printf("%d", num);
}﻿
