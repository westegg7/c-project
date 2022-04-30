#include <stdio.h>

int main()
{
	char ch;
	int i;

	while((ch = getchar()) != '\n')
	{
		if(ch >= 'a' && ch <= 'z')
		{
			ch -= 'a' - 'A';
		}else if (ch >= 'A' && ch <= 'Z')
		{
			ch += 'a' - 'A';
		}

		putchar(ch);
	}

	return 0;
}
