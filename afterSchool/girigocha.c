#include <stdio.h>

int main()
{
    int ring, book;
    float ans;
    scanf("%d %d", &book, &ring);
    int tempbook = book / 3;
    book -= tempbook * 3;
    ring -= tempbook * 26;
    ans = 10 * tempbook;
    if (book)
    {
        book--;
        ring -= 13;
        ans += 5;
    }
    printf("%.1f\n", ans);
    printf("%d\n", ring);
    if (ring)
    {
        int tempring = ring / 3;
        ans += tempring;
        ring -= tempring;
        ans += ring ? 0.5 : 0;
    }
    printf("%.1f", ans);
}