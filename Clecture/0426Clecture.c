#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�����ʹ� �ּҸ� �����ϴ� �����̴�
//�迭�� �̸��� �ּ��̰� ����̴�

/*int main()
{
	int arr[3] = { 0,1,2 };
	int* p;//�����ʹ� �ּҸ� �����϶�� �ִ�
	p = arr;//�迭�� �̸� arr�� �ּҸ��� �ٸ���
	printf("arr�� �ּ� : %p\n", arr);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *p, *(p+1),*(p+2));
	return 0;

}*/
/*int main()
{
	int* p;//������ �����ϴ¹�
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
	(*pA)++; //a++ �� ���� �ǹ̸� ������
	printf("a   : %d \n", a);
	printf("*pA : %d \n", *pA);
	return 0;
}*/

int main()
{
	int a[5] = { 0,1,2,3,4 };
	printf("%d %d\n", a[0], a[1]);
	printf("%d %d\n", &a[0], &a[1]);
	printf("a�ּ� = %d a[0] �ּ� = %d\n", &a, &a[0]);
	int* p = 0; //�迭�� �̸��� �ּ� &�̸�[0]�� �ּҿ� ����
	printf("a�ּ�=%p\n",p);
	printf("a�ּ�=%p\n", a);
	printf("a�ּ�=%p\n", &a[0]);
	printf("a[1]�ּ�=%p\n", &a[1]);
	printf("a[1]�ּ�=%p\n", a + 1);
	return 0;
}