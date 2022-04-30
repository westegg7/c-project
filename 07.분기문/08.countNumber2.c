#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define PERIOD '.'

int main()
{
	char c;
	int count_char = 0, count_word = 0, count_line = 0;
	bool word_flag = false; // 새로운 단어가 시작되지 않았다.
	bool line_flag = false; // 새로운 줄이 시작되지 않았다.

	printf("Enter text : \n");

	while((c = getchar()) != PERIOD)
	{
		if(!isspace(c)) // isspace() : whitespace를 판별. whitespace 에는 공백, 개행, 수평,수직탭 등등이 있다.
			count_char++; // count non-space characters

		if(!isspace(c) && !line_flag) // flag를 이용한 이 구조는 매우중요!!
		{
			count_line++;
			line_flag = true;
		}
		if(c == '\n')
			line_flag = false;

		if(!isspace(c) && !word_flag)
		{
			count_word++;
			word_flag = true; // 새로운 단어가 시작되면 true로 바꿔준다. 그러면 조건식의 !word_flag 가 false가 되어 조건식전체가 false가 되어 whitespace가 나올때까지 실행되지 않는다.
		}
		if(isspace(c)) // 한 단어가 끝남.
			word_flag = false; // whitespace 가 나왔기때문에  word_flag의 값이 false가 되고 다음 문자가 나왔을때 위의 식으로 단어를 카운트 할 수 있다.
	}

	printf("Characters = %d, Words = %d, Lines = %d\n", count_char, count_word, count_line);


	return 0;
}
