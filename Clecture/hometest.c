#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int dice[20];// ���� ������ 1���� �迭
int Count, anssum;// Count�� �ֻ����� ������ ���� anssum�� ���� �ϴ� �հ踦 ����
void DICE(int X)
{
    int a, n, sum;
    for (a = 1; a < 7; a++)
    {
        dice[X] = a;
        if (X < Count)
            DICE(X + 1); //dice �迭�� ���� �־ ���� ������ �ٲپ� ���鼭 ���
        if (X == Count - 1) // �ֻ������� �迭�� Count��ŭ �־��� ��
        {
            sum = 0; // �հ踦 ������ ������ 0���� �ʱ�ȭ
            for (n = 0; n < Count; n++) // sum�� �迭�� ����ִ� ���� ��� ����
                sum += dice[n];
            if (sum == anssum) // �������� �˻��ؼ� �������
            {
                for (n = 0; n < Count; n++) //����ϴ� �κ�
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
    if (Count > anssum || Count * 6 < anssum) // ���ʿ� ���� ��� �� �� ���°�� ���
        printf("���� ���� �� �����ϴ�.\n");
    else
        DICE(0);
    //Ȯ�� ���ϴ� ��(times(��µ� ����) / 6^�ֻ����� ����(��� ����� ��)) x 100
    return 0; //����Լ� ����
}