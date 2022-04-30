#include <stdio.h>

int main()
{
	char c;

	while(1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
			break;
	}

	return 0;
}
