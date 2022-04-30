#include <stdio.h>

int main()
{
	const int code = 1234;
	int guess;

	do
	{
		printf("input secret code : ");
		scanf("%d", &guess);
	} while (guess != code);

	printf("Success!");

	return 0;
}
