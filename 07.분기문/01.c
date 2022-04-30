#include <stdio.h>

int main()
{
	int number;

	printf("Input a positive integer : ");

	while(scanf("%d", &number) == 1)
	{
		if(number % 2 == 0)
		{
			printf("even\n");
		}else
		{
			printf("odd\n");
		}

		printf("Input a positive integer : ");
	}
	return 0;
}
