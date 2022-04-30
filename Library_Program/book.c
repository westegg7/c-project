#include <stdio.h>
#include "book.h"
#include "str.h"

int add_book(struct Book *a, int *num_total_book) {
	printf("등록하시려는 책의 이름을 입력해주세요 : ");
	scanf("%s", a->title);
	printf("저자명을 입력해주세요 : ");
	scanf("%s", a->author);
	printf("출판사명을 입력해주세요 : ");
	scanf("%s", a->publisher);

	a->borrowed = 0;
	(*num_total_book)++;

	printf("등록 완료!\n\n");

	return 0;
}

int search_book(struct Book *a, int *num_total_book) {
	int choice;
	int i;
	int num_search_result = 0;
	char keyword[30];

	while (1) {
		printf("원하시는 키워드를 선택해주세요. \n");
		printf("1. 책이름으로 검색\n");
		printf("2. 저자명으로 검색\n");
		printf("3. 출판사명으로 검색\n");
		printf("4. 뒤로 가기\n");
		scanf("%d", &choice);

		if (choice < 1 || choice > 4) {
			printf("잘못된 입력입니다. 다시 입력해주세요. \n\n");
			getchar();
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
		for (i = 0; i < *num_total_book; i++){
			if (search_str(a[i].title, keyword)) {
				printf("%d // %s // %s // %s \n\n", i, a[i].title, a[i].author, a[i].publisher);
				num_search_result++;
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
	} else if (choice == 2) {
		for (i = 0; i < *num_total_book; i++){
			if (search_str(a[i].author, keyword)) {
				printf("%d // %s // %s // %s \n\n", i, a[i].title, a[i].author, a[i].publisher);
				num_search_result++;
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
	} else if (choice == 3) {
		for (i = 0; i < *num_total_book; i++){
			if (search_str(a[i].publisher, keyword)) {
				printf("%d // %s // %s // %s \n\n", i, a[i].title, a[i].author, a[i].publisher);
				num_search_result++;
			} else if (i == *num_total_book - 1 && num_search_result == 0) {
				printf("찾으시는 도서가 없습니다.\n\n");
			}
		}
	}

	return 0;
}

int borrow_book(struct Book *a, int *num_total_book) {
	int i;

	while(1) {
		printf("대출을 원하시는 책의 번호를 입력하세요 : ");
		scanf("%d", &i);

		if (a[i].borrowed == 1) {
			printf("해당 도서가 대출중입니다.\n\n");
			return 0;
		}
		if (i >= 0 && i <= *num_total_book) {
			printf("아래의 책을 대출합니다.\n %d // %s // %s // %s \n", i, a[i].title, a[i].author, a[i].publisher);
			a[i].borrowed = 1;
			printf("대출 완료!\n\n");
			return 0;
		} else {
			printf("잘못된 입력입니다. 0부터 %d 사이의 번호를 입력하세요.\n", *num_total_book);
		}
	}

	return 0;
}

int return_book(struct Book *a, int *num_total_book) {
	int i;

	while(1) {
		printf("반납을 원하시는 책의 번호를 입력하세요 : ");
		scanf("%d", &i);

		if (a[i].borrowed == 0) {
			printf("해당 도서는 대출중이 아닙니다. \n\n");
			return 0;
		}
		if (i >= 0 && i <= *num_total_book) {
			printf("아래의 책을 반납합니다.\n %d // %s // %s // %s \n", i, a[i].title, a[i].author, a[i].publisher);
			a[i].borrowed = 0;
			printf("반납 완료!\n\n");
			return 0;
		} else {
			printf("잘못된 입력입니다. 0부터 %d 사이의 번호를 입력하세요.\n", *num_total_book);
		}
	}

	return 0;
}
