#include <stdio.h>

int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book);

int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book);

int search_str(char *str1, char *str2);

int borrow_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book);
int return_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book);


int main() {
	char book_name[100][30];
	char auth_name[100][30];
	char publ_name[100][30];
	int borrowed[100];

	int choice;
	int num_total_book = 0;

	while(1) {
		printf("원하시는 메뉴를 선택해주세요\n");
		printf("1. 도서 등록\n");
		printf("2. 도서 검색\n");
		printf("3. 도서 대출\n");
		printf("4. 도서 반납\n");
		printf("5. 프로그램 종료\n\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
				break;
			case 2:
				search_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
				break;
			case 3:
				borrow_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
				break;
			case 4:
				return_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
				break;
			case 5:
				return 0;
			default:
				printf("잘못된 입력입니다. 다시 입력해주세요\n");
				break;
		}
	}
	printf("\n");

	return 0;
}

int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book) {
	printf("새롭게 책을 등록합니다.\n");
	printf("책 제목을 입력해주세요 :  ");
	scanf("%s", book_name[*num_total_book]);
	printf("저자명을 입력해주세요 :  ");
	scanf("%s", auth_name[*num_total_book]);
	printf("출판사명을 입력해주세요 :  ");
	scanf("%s", publ_name[*num_total_book]);

	borrowed[*num_total_book] = 0;
	(*num_total_book)++;

	printf("등록 완료!\n\n");

	return 0;
}

int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book) {
	char keyword[30];
	int choice;
	int i;
	int num_search_result = 0;

	while (1) {
		printf("원하시는 키워드를 선택해주세요. \n");
		printf("1. 책이름으로 검색\n");
		printf("2. 저자명으로 검색\n");
		printf("3. 출판사명으로 검색\n");
		printf("4. 뒤로 가기\n");
		scanf("%d", &choice);

		if (choice < 1 || choice > 4) {
			printf("잘못된 입력입니다. 다시 입력해주세요. \n\n");
		} else if(choice == 4) {
			printf("\n");
			return 0;
		} else if (choice > 0 && choice < 5){
			break;
		}
	}

	printf("키워드를 입력해주세요. ");
	scanf("%s", keyword);

	if (choice == 1) {
		for (i = 0; i < *num_total_book; i++) {
			if (search_str(book_name[i], keyword)) {
				printf("%d // %s // %s // %s \n\n", i, book_name[i], auth_name[i], publ_name[i]);
				num_search_result++;
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
	} else if (choice == 2) {
		for (i = 0; i < *num_total_book; i++) {
			if (search_str(auth_name[i], keyword)) {
				printf("%d // %s // %s // %s \n\n", i, book_name[i], auth_name[i], publ_name[i]);
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
	} else if (choice == 3) {
		for (i = 0; i < *num_total_book; i++) {
			if (search_str(publ_name[i], keyword)) {
				printf("%d // %s // %s // %s \n\n", i, book_name[i], auth_name[i], publ_name[i]);
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
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
					return 1;
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

	return 0;
}

int borrow_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book) {
	int i;

	while(1){
		printf("대출하실 책의 번호를 입력해주세요.  ");
		scanf("%d", &i);

		if (borrowed[i] == 1) {
			printf("해당 도서가 이미 대출중입니다. \n\n");
			return 0;
		}

		if (i >= 0 && i <= *num_total_book) {
			printf("아래의 책을 대출합니다. \n %d // %s // %s // %s \n", i, book_name[i], auth_name[i], publ_name[i]);
			borrowed[i] = 1;
			printf("대출 완료!\n\n");
			return 0;
		} else {
			printf("0부터 %d 사이의 번호를 입력해주세요.\n\n", *num_total_book);
		}
	}

	return 0;
}

int return_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int *borrowed, int *num_total_book) {
	int i;

	while(1){
		printf("반납하실 책의 번호를 입력해주세요.  ");
		scanf("%d", &i);

		if (borrowed[i] == 0) {
			printf("대출 중인 도서가 아닙니다. \n\n");
			return 0;
		}

		if (i >= 0 && i <= *num_total_book) {
			printf("아래의 책을 반납합니다. \n %d // %s // %s // %s \n", i, book_name[i], auth_name[i], publ_name[i]);
			borrowed[i] = 0;
			printf("반납 완료!\n\n");
			return 0;
		} else {
			printf("0부터 %d 사이의 번호를 입력해주세요.\n\n", *num_total_book);
		}
	}

	return 0;
}
