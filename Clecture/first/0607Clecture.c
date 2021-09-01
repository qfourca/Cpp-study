#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*
struct point
{
	int x, y;
};
int main()
{
	struct point p;
	p.x = 1;
	p.y = 2;
	printf("xÁÂÇ¥ : %d, yÁÂÇ¥ : %d\n", p.x, p.y);
	struct point p1;
	p1.x = 3;
	p1.y = 4;
	printf("xÁÂÇ¥ : %d, yÁÂÇ¥ : %d\n", p1.x, p1.y);
	double a, b, c;
	a = p1.x - p.x;
	b = p1.y - p.y;
	c = sqrt(a * a + b * b);
	printf("%.2f\n", c);
	return 0;
}*/

int main()
{
	FILE* fp;
	/*
	fp = fopen("myfile.txt", "r");
	char name[80] = "";
	int myAge;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d", name, &myAge);
		printf("%s %d\n", name, myAge);
	}
	fclose(fp);*/
	fp = fopen("myfile.txt", "w");
	char arr[3][20];
	int age[3];
	for (int i = 0; i < 3; i++)
		scanf("%s %d", arr[i], &age[i]);
	for(int i = 0;i<3;i++)
		fprintf(fp, "%s %d\n", arr[i], age[i]);
	fclose(fp);

	return 0;
	
}