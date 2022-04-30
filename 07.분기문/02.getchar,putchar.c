#include <stdio.h> // getchar(), putchar()

int main()
{
	char ch;

	//ch = getchar(); // buffer !!!
	// putchar(ch);

	//while(ch != '\n') //Use '\n' to find the end of a sentence
	while((ch = getchar()) != '\n')
	{
		//for(int i = '0'; i <= '9'; ++i)
			if(ch >= '0' && ch <= '9')
				ch = '*';

		putchar(ch);

		//ch = getchar();
	}
	putchar(ch);

	return 0;
}
