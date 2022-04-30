#include <stdio.h>

int main()
{
	const int NUM_ROW = 10;
	const int FIRST_CHAR = 'A';

	int r;
	int c;

	for(r = 0; r < NUM_ROW; ++r)
	{
		for(c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
		{
			printf("%c ", c);
		}

		printf("\n");
	}

	return 0;
}
