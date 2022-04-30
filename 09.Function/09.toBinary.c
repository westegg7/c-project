#include <stdio.h>

void print_binary_loop(unsigned long n);
void print_binary(unsigned long n);

int main()
{
	unsigned long n = 10;

	print_binary_loop(n);
	print_binary(n);

	return 0;
}




void print_binary_loop(unsigned long n)	//이 반복문으로는 구현이 안된다. 나중에 나올 배열을 통해 거꾸로 출력해야한다.
{
	unsigned long remainder;

	for(; n > 0; n = n / 2)
	{
		remainder = n % 2;
		printf("%lu", remainder);
	}
	printf("\n");

	return;


	// while(1)	//강의에 나온 풀이
	// {
	// 	int quotient = n / 2;
	// 	int remainder = n % 2;

	// 	printf("%d", remainder);

	// 	n = quotient;

	// 	if(n == 0) break;
	// }

	// return;
}


void print_binary(unsigned long n)
{
	int remainder = n % 2;

	if(n > 1)
	{
		print_binary(n / 2);
	}

	printf("%d", remainder);	// 빠져나오면서 출력.

	return;



	// int remainder = n % 2;	// 홍정모 쌤의 풀이

	// if(n >= 2)
	// 	print_binary(n / 2);

	// printf("%d", remainder);

	// return;
}
