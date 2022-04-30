/* 사용자를 배려하며 입력을 체크하고 입력이 잘못되었을 경우 알려준다. */

#include <stdio.h>

long get_long(void);

int main()
{
	long number;

	while (1)
	{
		printf("Please input a integer between 1 and 100.\n");
		number = get_long();	// 정수가 입력될때까지 반복해서 입력을 받는 함수.

		if(number > 1 && number < 100)
		{
			printf("OK. Thank you.\n");
			break;
		}
		else
			printf("Wrong input.\n");
	}
		printf("Your input %ld is between 1 and 100. \n", number);


	return 0;
}


long get_long(void)
{

	long input;
	char c;

	while (scanf("%ld", &input) != 1)	// 문자열이 입력되면 scanf의 값이 0이 되어서 반복문이 실행된다.
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n')
			putchar(c);	//input left in buffer

		printf(" - is not an integer. Please try again.\n");
	}

	return input;
}
