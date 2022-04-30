#include <stdio.h>

int main()
{
	int user_input;
	char c;

	printf("Enter an integer:\n");

	while (scanf("%d", &user_input) != 1)
	{
		while ((c = getchar()) != '\n')
			putchar(c);
		printf(" is not an integer\n");
		printf("Enter an integer:\n");
	}

	return 0;
}
