/* 문제 4
- N 값을 입력 받아서 1부터 N 까지의 소수의 개수를 출력하는 함수.*/
#include <stdio.h>

int count_prime_numbers(int n)
{
	int i, j;
	int count = 0;
	int count_prime = 0;

	for (i = 2; i <= n; i++)
	{
		for (j = 2; j < i; j++)
		{
			if(i % j == 0)
				break;
		}
		if (i == j)
			count_prime++;
	}

	return count_prime;
}

int main()
{
	int input = 100;
	// printf("숫자를 입력하세요 : ");
	// scanf("%d", &input);

	printf("1부터 %d까지의 소수의 개수는 : %d \n", input, count_prime_numbers(input));



	return 0;
}
