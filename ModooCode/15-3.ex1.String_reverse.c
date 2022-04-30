#include <stdio.h>

int reverse_str(char *str, char *str_reverse);

int main() {
	char str[100];
	char str_reverse[100];

	printf("문자열을 입력하세요 :");
	scanf("%s", str);

	reverse_str(str, str_reverse);

	printf("%s", str_reverse);

	return 0;
}

int reverse_str(char *str, char *str_reverse) {
	int count = 0;

	while (*str) {
		str++;
		count++;
	}
	str--;

	while (count--) {
		*str_reverse = *str;
		str--;
		str_reverse++;
	}
	*str_reverse = '\0';

	return 0;
}
