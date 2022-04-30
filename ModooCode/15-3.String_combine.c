#include <stdio.h>

int combine_str(char *str1, char *str2, char *str_combined);

int main() {
	char str1[] = "Michael Jordan\n";
	char str2[] = "Kobe Bryant";
	char str_combined[100];

	combine_str(str1, str2, str_combined);

	printf("%s", str_combined);

	return 0;
}

int combine_str(char *str1, char *str2, char *str_combined) {
	while (*str1) {
		*str_combined = *str1;
		str1++;
		str_combined++;
	}
	while (*str2) {
		*str_combined = *str2;
		str2++;
		str_combined++;
	}
	*str_combined = '\0';

	return 1;
}
