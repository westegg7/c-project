#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
*/

int fibonacci(int number);

int main()
{
	for(int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	printf("%d", fibonacci(5));

	return 0;
}


int fibonacci(int number)
{
	if(number > 2)
		return fibonacci(number - 1) + fibonacci(number - 2);	// double recursion
	else
		return 1;
}

// 재궈함수의 장점 : 간결해질 수 있다. 단점 : 메모리의 비효율적인 사용, 중복된 계산.
