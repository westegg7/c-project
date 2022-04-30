#include <stdio.h>
#include "book.h"

int main() {
	struct Book library[100];
	int user_choice;
	int num_total_book = 0;

	while (1) {
		printf("< 도서관리 프로그램 >\n");
		printf("원하시는 메뉴 번호를 입력해주세요.\n");
		printf("1. 도서 등록\n");
		printf("2. 도서 검색\n");
		printf("3. 도서 대출\n");
		printf("4. 도서 반납\n");
		printf("5. 프로그램 종료\n\n");
		scanf("%d", &user_choice);

		switch (user_choice) {
			case 1:
				add_book(&library[num_total_book], &num_total_book);
				break;
			case 2:
				search_book(library, &num_total_book);
				break;
			case 3:
				borrow_book(library, &num_total_book);
				break;
			case 4:
				return_book(library, &num_total_book);
				break;
			case 5:
				return 0;
			default:
				printf("잘못된 입력입니다. 1~5의 번호를 입력해주세요.\n\n");
				break;
		}
	}

	return 0;
}


