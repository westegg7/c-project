#include <stdio.h>

void display(char c, int rows, int cols);

int main()
{
	char c;
	int rows, cols;

	printf("input one character and two numbers : \n");

	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);	// 줄바꿈이 남아있는 상태

		while (getchar() != '\n')
			continue;

		display(c, rows, cols);

		printf("input one character and two numbers \n");
		printf("You want quit, Press Enter key.\n");
	}

	return 0;
}

void display(char c, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				putchar(c);
			}
			printf("\n");
		}
}
