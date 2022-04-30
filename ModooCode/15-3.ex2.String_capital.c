/*대문자와 소문자는 아스키테이블 상에서 십진수 32의 차이*/
#include <stdio.h>

int change_capital_str(char *str);

int main() {
	char str[100];

	printf("문자열을 입력하세요. ");
	scanf("%s", str);

	printf("%s\n",str);

	change_capital_str(str);

	printf("%s\n",str);

	return 0;
}

int change_capital_str(char *str) {
	while (*str) {
		if (*str >= 'A' && *str <= 'Z') {
			*str += 32;
		}
		else if (*str >= 'a' && *str <= 'z') {
			*str -= 32;
		}
		str++;
	}

	return 0;
}
