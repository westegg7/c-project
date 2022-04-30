#include "str.h"

int search_str(char *str1, char *str2) {
	char *str22 = str2;

	while(*str1) {
		if (*str1 == *str2) {
			while(1) {
				str1++;
				str2++;
				if (*str2 == 0) {
					return 1;
				} else if (*str1 != *str2) {
					break;
				}
			}
		}
		str1++;
		str2 =
		str22;
	}

	return 0;
}
