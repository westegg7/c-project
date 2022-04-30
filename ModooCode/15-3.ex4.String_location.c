#include <stdio.h>

int search_str(char *str1, char *str2);

int main() {
	char str1[100];
	char str2[100];

	printf("참조할 문자열을 입력하세요. ");
	scanf("%s", str1);
	printf("검색할 문자열을 입력하세요. ");
	scanf("%s", str2);

	if (search_str(str1, str2) == -1) {
		printf("찾으시는 문자열이 없습니다.\n");
	} else {
		printf("찾으신 문자는 %d번째에 있습니다.\n", search_str(str1, str2));
	}


	return 0;
}

int search_str(char *str1, char *str2) {
	int count = 1;
	char *str22 = str2;

	while (*str1) {
		if (*str1 == *str2) {
			while (1) {
				str1++;
				str2++;
				if(*str2 == 0) {
					return count;
				}
				else if (*str1 != *str2) {
					break;
				}
			}
		}
		str2 = str22;
		str1++;
		count++;
	}

	return -1;
}


/*

*/
