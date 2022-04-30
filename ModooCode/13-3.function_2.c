/* 함수 포인터 */
#include <stdio.h>

int max(int a, int b);
int donothing(int c, int k);
// int increase(int (*arr)[3], int row);	//첫번째 인자의 형은 int (*)[3]

int main()
{
	int a, b;
	int (*pfunc)(int, int);
	pfunc = max;

	scanf("%d %d", &a, &b);
	printf("max(a,b) : %d\n", max(a, b));
	printf("pfunc(a,b) : %d\n", pfunc(a, b));

	pfunc = donothing;	// max와 donothing 함수 모두 int형 리턴값을 가지고 인자도 int형 두 개로 동일하므로

	printf("donothing(1,1) : %d\n", donothing(1, 1));
	printf("pfunc(1,1) : %d\n", pfunc(1, 1));

	return 0;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;

	return 0;
}

int donothing(int c, int k)
{
	return 1;
}
