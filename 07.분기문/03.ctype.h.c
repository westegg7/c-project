#include <stdio.h>
#include <ctype.h> // islower(), isupper(), tolower(), toupper(),

int main ()
{
	char ch;

	while((ch = getchar()) != '\n')
	{
		if(islower(ch))
			ch = toupper(ch);
		else if(isupper(ch))
			ch = tolower(ch);

		//for(int i = 0; i <= '9'; ++i)
		if(isdigit(ch) != 0)
			ch = '*';

		putchar(ch);
	}

	return 0;
}

