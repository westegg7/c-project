#include <stdio.h>
#include <stdlib.h>

#define SLEN 101

struct book {
    char title[SLEN];
    char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n_ptr);
void read_books2(const char* filename, struct book** books_dptr, int* n_ptr);

int main() {
    int temp;
    int n = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
    if (!my_books) exit(1);

    my_books[0] = (struct book){"The Great Gatsby", "F. Scott Fitzerald"};
    my_books[1] = (struct book){"Hemlet", "William Shakespeare"};
    my_books[2] = (struct book){"The Odyssey", "Homer"};

    print_books(my_books, n);

    printf("\nWrting to a file.\n");
    write_books("books", my_books, n);
    free(my_books);
    n = 0;
    printf("Done.\n");

    printf("\nPress any key to read data from a file.\n\n");
    temp = getchar();

    my_books = read_books("books", &n);
    // read_books2("books", &my_books, &n);     // return 값이 없다.

    print_books(my_books, n);

    free(my_books);
    n = 0;

    return 0;
}

void print_books(const struct book* books, int n) {
    for (int i = 0; i < n; i++) 
        printf("Book %d : \"%s\" written by %s.\n", i + 1, books[i].title, books[i].author);
}

void write_books(const char* filename, const struct book* books, int n) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    fprintf(fp, "%d\n", n); // number of books

    // for (int i = 0; i < n; i++) {
    //     fwrite(books[i].title, sizeof(char), SLEN, fp);
    //     fputc('\n', fp);
    //     fwrite(books[i].author, sizeof(char), SLEN, fp);
    //     fputc('\n', fp);
    // }

    for (int i = 0; i < n; i++)
        fprintf(fp, "%s\n%s\n", books[i].title, books[i].author);

    fclose(fp);
}

struct book* read_books(const char* filename, int *n_ptr) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    int flag;
    flag = fscanf(fp, "%d%*c", n_ptr);   // Remove last \n
    if (flag != 1) {
        printf("File read failed");
        exit(1);
    }

    struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr);

    if (!books) {
        printf("Malloc() failed.");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; i++) {
        flag = fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].title, books[i].author);
        if (flag != 2) {
            printf("File read failed.");
            exit(1);
        } 
    }

    fclose(fp);

    return books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n_ptr) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fputs("Can't open file.", stderr);
        exit(1);
    }

    int flag;
    flag = fscanf(file, "%d%*c", n_ptr);
    if (flag != 1) {
        printf("File read failed");
        exit(1);
    }

    struct book* books = (struct book*)malloc(sizeof(struct book) * (*n_ptr));
    if (books == NULL) {
        printf("Malloc() failed");
        exit(1);
    }

    for (int i = 0; i < *n_ptr; i++) {
        flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].title, books[i].author);
        if (flag != 2) {
            printf("File read failed");
            exit(1);
        }
    }

    // books_dptr = &books;    // 이 함수가 끝나면 books 변수자체는 사라지므로 주소를 전달하는건 의미가 없다.
    *books_dptr = books;    // 구조체(할당된 메모리의 첫주소)를 대입한다. 메모리해제는 함수 밖에서.

    fclose(file);
}