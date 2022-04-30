#include <stdio.h>

void display(char c, int rows, int cols);

int main()
{
	char c;
	int rows, cols;

	// /* 1번째 방법 - scanf는 모든 값을 입력을 받아야하기때문에 깔끔하게 종료되지 않는다. 그러므로 2번째의 getchar()와 함께 사용한다. */
	// while (1)
	// {

	// 	scanf("%c %d %d", &c, &rows, &cols);
	// 	while(getchar() != '\n')	// 위 입력값으로부터 '\n'을 없애주지 않으면 두번째 루프는 버퍼에 남아있던 '\n'부터 시작하게 되어 꼬이게 된다.
	// 		continue;

	// 	display(c, rows, cols);
	// 	if (c == '\n')
	// 		break;
	// }


	/* 2번째 방법 */
	printf("Input one character and two integers : \n");
	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		while(getchar() != '\n')
			continue;

		display(c, rows, cols);

		printf("Input one character and two integers : \n");
		printf("Press Enter to quit.\n");
	}

	return 0;
}

void display(char c, int rows, int cols)
{
	int i, j;

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			putchar(c);
		}
		putchar('\n');
	}
}


