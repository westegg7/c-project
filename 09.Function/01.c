#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>	// 간단한 bool타입을 활용해 printf("\n")(15)을 없애보자

#define WIDTH	40
#define NAME	"Hyunwoo Han"
#define ADDRESS	"Kichijoji, Tokyo, Japan"

void print_chars(char c, int n_chars, bool print_new_line);
void print_centered_str(char str[]);	// prototype

int main()	// 네임카드 만들기
{
	print_chars('*', WIDTH, true);	// argument
	//printf("\n");

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("with yon");	// 함수가 있으면 이렇게 간단하게 활용가능

	print_chars('*', WIDTH, false);

	return 0;
}




void print_chars(char c, int n_chars, bool print_new_line)	//parameter
{
	for (int i = 0; i < n_chars; i++)
		printf("%c", c);
	if (print_new_line)	// if(print_new_line == true)와 같은 뜻.
		printf("\n");
}

void print_centered_str(char str[])
{
	int n_blank = 0;
	n_blank = (WIDTH - strlen(str)) / 2;
	print_chars(' ', n_blank, false);
	printf("%s\n",str);
}


/*
함수가 필요할 때.
1. 기능을 확장할때
2. 같은 기능이 여러번 반복되어 나타날때
3. 함수의 이름을 읽는 것만으로 코드파악이 편리.
4. 변수를 통해 한꺼번에 수정이 가능하게됨. #define
*/
