#include <stdio.h>

int loop_factorial(int n);
int recursive_factorial(int n);

int main()
{
	int num = 10;

	printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factorial(num));

	return 0;
}

int loop_factorial(int n)
{
	int result;

	for(result = 1; n > 1; n--)
	{
		result *= n;
	}
	return result;
}

int recursive_factorial(int n)
{
	if(n > 0)
	{
		return n * recursive_factorial(n - 1);
	}
	else
		return 1;
}
