struct Book {
	char title[30];
	char author[30];
	char publisher[30];
	int borrowed;
};

int add_book(struct Book *a, int *num_total_book);
int search_book(struct Book *a, int *num_total_book);
int borrow_book(struct Book *a, int *num_total_book);
int return_book(struct Book *a, int *num_total_book);
