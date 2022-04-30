#include <stdio.h>

int main()
{
	int i;

	_Bool boolean_true = (1 < 2); // _Bool 정수형
	_Bool boolean_false = (1 > 2);

	printf("True is %d\n", boolean_true);
	printf("False is %d\n", boolean_false);

	return 0;
}
