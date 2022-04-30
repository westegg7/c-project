#include <stdio.h>

int compare_str(char *str1, char *str2);

int main() {
	char str1[] = "MJ";
	char str2[] = "Kob";
	char str3[] = "MJ";
	char str4[] = "MJORDAN";

	if (compare_str(str1, str2)) {
		printf("일치\n");
	} else {
		printf("불일치\n");
	}
	if (compare_str(str1, str3)) {
		printf("일치\n");
	} else {
		printf("불일치\n");
	}
	if (compare_str(str1, str4)) {
		printf("일치\n");
	} else {
		printf("불일치\n");
	}

	return 0;
}

int compare_str(char *str1, char *str2) {
	while(*str1) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0') return 1;

	return 0;
}
