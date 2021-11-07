#include <stdio.h>
#include <math.h>
int main()
{
    int count;
    int max = 0;
    double length[1000];
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        int tempX, tempY;
        scanf("%d %d", &tempX, &tempY);
        tempX = tempX * tempX;
        tempY = tempY * tempY;
        length[i] = sqrt(tempX + tempY);
        if (length[i] > max)
            max = length[i];
    }

    for (int i = count - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (length[j] > length[j + 1])
            {
                double t = length[j];
                length[j] = length[j + 1];
                length[j + 1] = t;
            }
    for (int i = 0; i < count; i++)
        printf("%lf\n", length[i]);
}
