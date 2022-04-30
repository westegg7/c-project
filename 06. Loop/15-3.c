#include <stdio.h>

int main()
{
	int NUM_ROW;
	const int FIRST_CHAR = 'A';
	int LAST_CHAR;

	printf("input the count of row : ");
	scanf("%d", &NUM_ROW); // 몇줄로 표시하고 싶은지 입력받음

	LAST_CHAR = FIRST_CHAR + NUM_ROW - 1; //마지막 알파벳

	int r;
	int c;

	printf("\n");

	for(r = 0; r < NUM_ROW; ++r)
	{
		for(c = FIRST_CHAR + r; c <= LAST_CHAR; ++c)
		{
			printf("%c ", c);
		}

		printf("\n");
	}

	return 0;
}
