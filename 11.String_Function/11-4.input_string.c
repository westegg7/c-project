#include <stdio.h>
#define STRLEN 20

char* custom_string_input(char* st, int n);
int main()
{
	// int a;

	// scanf("%d", &a);
	// printf("%d\n", a);
	// while (getchar() != '\n');	// 버퍼를 비워야 다음 입력을 받을 수 있다!!!

	// char words[STRLEN];
	// // // gets_s(words, sizeof(words));	// c11

	// fgets(words, STRLEN, stdin);	// does not remove '\n'

	// int i = 0;
	// while (words[i] != '\n' && words[i] != '\0') 
	// 	i++;
	// if (words[i] == '\n')
	// 	words[i] = '\0';

	// fputs(words, stdout);	// does not add '\n'
	// printf("\n");
	// fputs("END", stdout);


	// char small_array[5];
	// puts("Enter long strings : ");
	// // fgets(small_array, sizeof(small_array), stdin);	// 1234(null)까지. FILE *_Stream, 정상종료시 입력받은 포인터를 반환, EOF을 만나면 NULL 반환
	// printf("%p\n", small_array);
	// printf("%p\n", fgets(small_array, sizeof(small_array), stdin));

	// fputs(small_array, stdout);	//


	// char small_array[5];
	// puts("Enter long strings");
	// while (fgets(small_array, sizeof(small_array), stdin) != NULL && small_array[0] != '\n')
	// 	fputs(small_array, stdout);
	// 	// puts(small_array);	// puts()는 '\n'까지 출력되어버린다.

	// char str1[6], str2[6];
	// // int count = scanf("%5s %5s", str1, str2);
	// // int count = scanf("%6s %6s", str1, str2);	// 런타임 에러
	// printf("%s | %s\n", str1, str2);


	char word[11];
	puts(custom_string_input(word, 11));

	return 0;
}

char* custom_string_input(char* st, int n) 
{
	char* ret_ptr;
	int i = 0;

	ret_ptr = fgets(st, n, stdin);

	if (ret_ptr)
	{
		while (st[i] != '\0' && st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')	// clear buffer
				continue;
	}

	return ret_ptr;
}