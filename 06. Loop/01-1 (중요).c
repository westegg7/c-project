#include <stdio.h>

int main()
{
	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");

	while(scanf("%d", &num) == 1) // while(조건식) 조건식에 함수를 넣을 수 있다.
	{
		printf("Enter an integer (q to quit) : ");
		sum = sum + num;
	}

	printf("Sum = %d\n", sum);

	return 0;
}
