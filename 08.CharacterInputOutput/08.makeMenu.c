#include <stdio.h>
#include <stdlib.h>

void count(void);

int main()
{
	int input, caseC = 1;
	int i;

	while(1)
	{
		printf("Enter the letter of your choice :\n");
		printf("a. avengers\tb. beep\n");
		printf("c. count\tq. quit\n");

		input = getchar();

		switch(input)
		{
		case 'a':
			printf("Avengers Assemble!\n");
			break;
		case 'b':
			putchar('\a'); //Beep
			break;
		case 'c':
			count(); // 정수 하나를 받는 함수. 문자입력시에는 재입력을 요구한다.
			break;
		case 'q':
			break;
		default:
			printf("Please try again.\n");

			break;
		}

		if(input == 'q')
			break;

		while(getchar() != '\n')
			continue;
	}


	return 0;
}

void count(void)
{
	int user_input;
	char c;
	int i;

	printf("Enter an integer:\n");

	while (scanf("%d", &user_input) != 1)
	{
		while((c = getchar()) != '\n')
			putchar(c);
		printf(" is not an integer\n");
		printf("Enter an integer:\n");
	}
	for(i = 1; i <= user_input; i++)
	{
		printf("%d\n", i);
	}
}
