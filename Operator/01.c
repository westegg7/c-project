#include <stdio.h>

void draw(int n);

int main()
{
	int i = 5;
	char c = '#'; // 35
	float f = 7.1f;

	draw(i);
	draw((int)c);
	draw((int)f);

	return 0;
}

void draw(int n)  // draw asterisks
{
	while(n-- > 0)
		printf("*");
	printf("\n");
}
