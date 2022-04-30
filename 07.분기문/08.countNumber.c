#include <stdio.h>
#include <ctype.h>

#define PERIOD '.'

int main()
{
	int ch;
	int char_count = 0, word_count = 1, line_count = 1;


	printf("Enter text : \n");

	while((ch = getchar()) != PERIOD)  // 문제가 많다. 빈 줄은 카운트에서 빼고 빈칸 두개도 처리곤란.
	{
		if(ch != ' ' && ch != '\n')
			++char_count;
		if(ch == ' ')
			++word_count;
		if(ch == '\n')
			++line_count;
	}

	printf("Characters = %d, Words = %d, Lines = %d", char_count, word_count, line_count);

	return 0;
}
