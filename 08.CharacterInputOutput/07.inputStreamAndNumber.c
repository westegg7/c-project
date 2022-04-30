#include <stdio.h>

int main()
{
	char str[255];
	int i, i2;
	double d;

	scanf("%s %d %lf", str, &i, &d);
	printf("%s %d %f\n", str, i ,d);

	scanf("%s %d %d", str, &i, &i2);
	printf("%s %d %d\n", str, i, i2);

	char c;
	while ((c = getchar()) != '\n')
		putchar(c);

	printf("\n");

	return 0;
}
