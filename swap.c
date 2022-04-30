#include <stdio.h>

void swap(int* u, int* v)	//포인터변수. 변수의 주소값을 받는다.
{
	int temp = *u;
	*u = *v;
	*v = temp;
}

int main()
{
	int a = 123;
	int b = 456;

	//swap 함수. 이렇게 main함수 안에서 하면 변수가 동일하기 때문에 문제가 없지만 함수로 따로 만들면 스코프, 변수가 달라져 포인터가 필요해진다.
	swap(&a, &b);

	printf("%d %d\n", a, b);

	return 0;
}
