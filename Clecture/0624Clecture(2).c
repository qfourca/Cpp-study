#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _d Stu
{
	char name[20];
	int kor, eng, math;
};

int main() 
{
	Stu s1, s2, sum;
	scanf("%s %d %d %d", s1.name, &s1.kor, &s1.eng, &s1.math);
	scanf("%s %d %d %d", s2.name, &s2.kor, &s2.eng, &s2.math);
	strcpy(sum.name, "รัวี");
	sum.kor = s1.kor + s2.kor;
	sum.eng = s1.eng + s2.eng;
	sum.math = s1.math + s2.math;
	printf("รัวี %d %d %d", sum.kor, sum.eng, sum.math);
}
	