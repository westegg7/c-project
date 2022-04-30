#include <stdio.h>

int main() // Nested Loop
{
	const int NUM_ROW = 5;// 상수값을 이렇게 지정해두면 유지보수에 도움.
	const int FIRST_CHAR = 'A';
	const int LAST_CHAR = 'K';

	int r; //row loop
	int c; //character loop

	for(r = 0; r < NUM_ROW; ++r) //Outer Loop
	{
		for(c = FIRST_CHAR; c <= LAST_CHAR; ++c) //Inner Loop
		{
			printf("%c ", c);
		}
		printf("\n");
	}

	return 0;
}
