#include <stdio.h>

void my_func(int);

int main()
{
	my_func(1);	//input as an argument

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %p\n", n, &n);

	// my_func(n + 1);	//argument

	if(n < 4)
		my_func(n + 1);	//각각의 n들은 다른 변수이다.

	printf("Level %d, address of variable n = %p\n", n, &n);

	//TODO: stop condition
	//TODO: tail recursion
}
