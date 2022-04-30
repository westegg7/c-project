#include <stdio.h>

int main()
{
	int a = 7;

	printf("%d\n",a);

	int* ptr = &a;

	*ptr = 8;

	printf("%d\n",a);

	int** pptr = &ptr;

	printf("%p %p %d\n", &ptr, pptr, **pptr);	//**pptr = a, *pptr = ptr, pptr = &ptr
	//double indirection

	**pptr = 9;	// *(*pptr) = *(ptr) = a = 9;

	printf("%d", a);

	printf("%p", &a);

	return 0;
}
