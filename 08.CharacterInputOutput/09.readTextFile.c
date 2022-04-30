#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *file = NULL;
	char file_name[] = "my_file.txt";	// TODO: use scanf(...)

	file = fopen(file_name, "r");	// fopen : 파일을 읽거나 쓸수있는 파일통로를 열고 file이라는 포인트 변수에 저장한다. r or w read or write
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);
	fclose(file);

	return 0;
}
