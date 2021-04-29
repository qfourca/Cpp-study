#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//포인터는 주소를 저장하는 변수이다
//배열의 이름은 주소이고 상수이다

/*int main()
{
	int arr[3] = { 0,1,2 };
	int* p;//포인터는 주소를 저장하라고 있다
	p = arr;//배열의 이름 arr은 주소마다 다르다
	printf("arr의 주소 : %p\n", arr);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p+1),*(p+2));
	return 0;

}*/
/*int main()
{
	int* p;//포인터 선언하는법
	int a = 100;
	printf("%d\n", a);
	p = &a;
	printf("%p %p\n", p, &a);
	printf("%d\n", *p);
	return 0;
}*/

/*int main()
{
	int num1 = 100, num2 = 200;
	int* pNum;
	pNum = &num1;
	*pNum = 50;
	pNum = &num2;
	*pNum = -30;
	printf("%d %d\n", num1, num2);
	return 0;
}*/

/*int main()
{
	int a = 2005;
	int* pA = &a;
	printf("pA : %p \n", pA);
	printf("&a : %p \n", &a);
	(*pA)++; //a++ 과 같은 의미를 가진다
	printf("a   : %d \n", a);
	printf("*pA : %d \n", *pA);
	return 0;
}*/

int main()
{
	int a[5] = { 0,1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%d %d\n", &a[0], &a[1]);
	printf("a주소 = %d a[0] 주소 = %d\n", &a, &a[0]);
	int* p = 0; //배열의 이름은 주소 &이름[0]의 주소와 같다
	printf("a주소=%p\n",p);
	printf("a주소=%p\n", a);
	printf("a주소=%p\n", &a[0]);
	printf("a[1]주소=%p\n", &a[1]);
	printf("a[1]주소=%p\n", a + 1);
	return 0;
}