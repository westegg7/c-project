#include <stdio.h>

int copy_str(char *str1, char *str2);

int main() {
	char str1[] = "Michael Jordan";
	char str2[] = "Kobe Bryant";

	printf("%s", str1);

	printf("\n");

	copy_str(str1, str2);

	printf("%s", str1);

	return 0;
}

int copy_str(char *str1, char *str2) {
	while(*str2) {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';

	return 1;
}
