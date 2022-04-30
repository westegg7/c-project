#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);

int main()
{
	int user_choice;

	while ((user_choice = get_choice()) != 'q')	//get_choice()에서 입력의 유효성을 검증하는 부분을 구현한다. (ex : try again)
	{
		switch(user_choice)
		{
		case 'a':
			printf("Avengers Assemble!\n");
			break;
		case 'b':
			putchar('\a'); //Beep
			break;
		case 'c':
			count();
			break;
		default:	// 프로그램 완성후에는 실행이 되면 안되는 코드. 디버깅 과정에서 프로그램의 문제점 파악을 위해 메시지를 준비.
			printf("Error with %d.\n", user_choice);
			exit(1);
			break;
		}
	}

	return 0;
}


void count(void)
{
	int n, i;

	printf("Enter an integer : \n");
	n = get_integer();
	for (i = 1; i <= n; i++)
		printf("%d\n",i);
	while (getchar() != '\n')	// get_integer()함수 내의 scanf에서 입력된 버퍼를 지운다.
		continue;
}

char get_choice(void)
{
	int user_input;

	printf("Enter the letter of your choice:\n");
	printf("a. avengers\tb. beep\n");
	printf("c. count\tq. quit\n");

	user_input = get_first_char();

	while ((user_input < 'a' || user_input > 'c') && user_input != 'q')
	{
		printf("Please try again\n");
		user_input = get_first_char();
	}

	return user_input;
}

char get_first_char(void)
{
	int ch;

	ch = getchar();	// 입력된 첫번째 문자를 대입받는다.
	while (getchar() != '\n')	// 두번째 문자 이후 나머지 문자를 버퍼에서 비운다.
		continue;

	return ch;
}

int get_integer(void)
{
	int input;
	char c;

	while (scanf("%d", &input) != 1)
	{
		while ((c = getchar()) != '\n')
			putchar(c);
		printf(" is not an integer. \nPlease try again.\n");
	}
	return input;
}
