#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 3 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
	int num = 4;

	printf("%ld\n", loop_factorial(num));
	printf("%ld\n", recursive_factorial(num));

	return 0;
}


long loop_factorial(int n)
{
	long result;

	for(result = 1; n > 1; n--)
	{
		result *= n;
	}

	return result;
}

long recursive_factorial(int n)
{
	if (n > 0)
	{
		return n * recursive_factorial(n - 1);	//tail (end) recursion (return 바로 뒤에 재귀적호출을 하는 것. 가장 깔끔한 구조, 수학적 정의에 따른. )
	}
	else
		return 1;
}
