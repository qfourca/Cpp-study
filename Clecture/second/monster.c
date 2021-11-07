#include <stdio.h>
int main()
{
    int attack, recovery, hp;
    scanf("%d %d %d", &attack, &recovery, &hp);
    int ans = 0;
    while (hp > 0)
    {
        hp -= attack;
        ans++;
        if (hp <= 0)
            break;
        hp += recovery;
    }
    printf("%d", ans);
}