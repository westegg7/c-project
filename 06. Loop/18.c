#include <stdio.h>

int compute_pow(int base, int exp);

int main()
{
	int base, exp, result;

	printf("input base number and exponent : ");

	while(scanf("%d %d", &base, &exp) == 2)
	{
		// result = 1;
		// for(int i = 0; i < exp; ++i)
		// 	result *= base;
		result = compute_pow(base, exp);

		printf("Result : %d\n", result);
	}

	return 0;
}

int compute_pow(int base, int exp)
{
	int i, result;

	result = 1;
	for(i = 0; i < exp; ++i)
		result *= base;

	return result;
}
