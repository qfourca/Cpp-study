#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int dice[20];// 값을 저장할 1차원 배열
int Count, anssum;// Count에 주사위의 개수를 저장 anssum에 나야 하는 합계를 저장
void DICE(int X)
{
    int a, n, sum;
    for (a = 1; a < 7; a++)
    {
        dice[X] = a;
        if (X < Count)
            DICE(X + 1); //dice 배열에 값을 넣어서 뒤쪽 값부터 바꾸어 가면서 출력
        if (X == Count - 1) // 주사위값을 배열에 Count만큼 넣었을 때
        {
            sum = 0; // 합계를 저장할 변수를 0으로 초기화
            for (n = 0; n < Count; n++) // sum에 배열에 들어있는 수를 모두 더함
                sum += dice[n];
            if (sum == anssum) // 정답인지 검사해서 맞을경우
            {
                for (n = 0; n < Count; n++) //출력하는 부분
                    printf("%d ", dice[n]);
                printf("\n");
            }
        }
    }
}
int main()
{
    scanf("%d %d", &Count, &anssum);
    printf("\n");
    if (Count > anssum || Count * 6 < anssum) // 애초에 값이 출력 될 수 없는경우 출력
        printf("값이 나올 수 없습니다.\n");
    else
        DICE(0);
    //확률 구하는 식(times(출력된 개수) / 6^주사위의 개수(모든 경우의 수)) x 100
    return 0; //재귀함수 응용
}