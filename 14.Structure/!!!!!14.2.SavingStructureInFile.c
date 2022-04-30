/* 
    14.1을 참고해 바이너리 파일을 쓰고 읽는 함수로 바꿔보자. 

    텍스트 파일을 우리가 손쉽게 수정할 수는 없지만 코드가 훨씬 간단해진다.
    다루는 데이터의 양이 많거나, 파일입출력의 속도가 중요한 경우를 포함해 대다수의 경우에는 바이너리 형태가 좋다.
    하지만 디버깅 등의 몇몇 경우에 있어 텍스트 형태가 필요하기도 하다.
*/

#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

struct book {
    char title[SLEN];
    char author[SLEN];
};

void print_books(struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
void read_books(const char* filename, struct book** books_dptr, int *n_ptr);

int main() {
    int n = 3;
    int temp;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
    if(my_books == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    my_books[0] = (struct book){"The Great Gatsby", "F.Scott Fitzerald"};
    my_books[1] = (struct book){"Hamlet", "William Shakespeare"};
    my_books[2] = (struct book){"The Odyssey", "Homer"};

    print_books(my_books, n);

    printf("\nWriting to a file.\n");
    write_books("book_list", my_books, n);
    printf("Done.\n\n");
    free(my_books);
    n = 0;

    printf("Press any key to read data from a file\n");

    temp = getchar();

    read_books("book_list", &my_books, &n);

    print_books(my_books, n);

    free(my_books);
    n = 0;

    return 0;
}

void print_books(struct book* books, int n) {
    for (int i = 0; i < n; i++) {
        printf("Book %d : \"%s\" written by %s.\n", i + 1, books[i].title, books[i].author);
    }
}

void write_books(const char* filename, const struct book* books, int n) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fputs("Can't open file.\n", stderr);
        exit(1);
    }

    fwrite(&n, sizeof(n), 1, file);
    fwrite(books, sizeof(struct book), n, file);

    fclose(file);
}

void read_books(const char* filename, struct book** books_dptr, int *n_ptr) {
    FILE* file = fopen("book_list", "rb");
    if (file == NULL) {
        fputs("Can't open a file", stderr);
        exit(1);
    }

    fread(n_ptr, sizeof(int), 1, file);

    struct book* books = (struct book*)malloc(sizeof(struct book) * (*n_ptr));

    fread(books, sizeof(struct book), *n_ptr, file);

    *books_dptr = books;

    fclose(file);
}
