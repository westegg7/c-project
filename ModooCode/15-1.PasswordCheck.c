#include <stdio.h>

int compare_str(char* str1, char* str2);

int main(){
	char str1[20];
	char str2[20];

	printf("비밀번호를 입력하세요.(20자 이내) ");
	scanf("%s", str1);
	printf("비밀번호를 확인해주세요. ");
	scanf("%s", str2);

	compare_str(str1, str2);

	return 0;
}

int compare_str(char* str1, char* str2){
	int i = 0;

	while(1){
		if(str1[i] != str2[i]){
			printf("비밀번호가 일치하지 않습니다.");
			break;
		}
		if(str1[i] == str2[i]){
			i++;
		}
		if(str1[i] == 0 && str2[i] == 0){
			printf("일치합니다.");
			break;
		}
	}
	return 0;
}

