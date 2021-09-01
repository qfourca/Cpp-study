#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _p
{
	double x, y;
}Point;


int main()
{
	Point p1, p2;
	scanf("%lf %lf", &p1.x, &p1.y);
	scanf("%lf %lf", &p2.x, &p2.y);
	printf("%.1f %.1f\n", (p1.x + p2.y) / 2.0, (p1.y + p2.y) / 2.0);
	return 0;
}
