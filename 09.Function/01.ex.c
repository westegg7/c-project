#include <stdio.h>
#include <string.h>

#define WIDTH 50
#define NAME "Hyunwoo Han"
#define ADDRESS "Kichijoji, Tokyo"

void print_stars(int width);
void print_spaces(char str[]);

int main()
{
	print_stars(WIDTH);
	print_spaces(NAME);
	print_spaces(ADDRESS);
	print_spaces("with you");
	print_stars(WIDTH);

	return 0;
}


void print_stars(int width)
{
	for(int i = 0; i < width; i++)
	{
		printf("*");
	}
	printf("\n");
}

void print_spaces(char str[])
{
	int i;
	int num_space =  (WIDTH - strlen(str)) / 2;

	for(i = 0; i < num_space; i++)
	{
		printf(" ");
	}
	printf("%s", str);
	printf("\n");
}
