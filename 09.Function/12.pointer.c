#include <stdio.h>

int main()
{
	int a = 7;

	int *a_ptr = &a;	// int type 변수의 주소만 가져올 수 있다. 4byte.

	*a_ptr = 8;

	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	int c = 9;

	c += *a_ptr;

	printf("%d", c);


	return 0;
}
