#include <stdio.h>

void print_binary_loop(unsigned long n);
void print_binary(unsigned long n);

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);
	print_binary(num);

	return 0;
}


void print_binary_loop(unsigned long n)
{
	int remainder;

	while(1)
	{
		remainder = n % 2;

		printf("%d", remainder);

		n /= 2;

		if(n < 1) break;
	}

	printf("\n");
}

void print_binary(unsigned long n)
{
	int remainder = n % 2;

	if(n > 1)
	{
		print_binary(n / 2);
	}

	printf("%d", remainder);

	return;
}
