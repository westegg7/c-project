#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

struct book {
    char title[SLEN];
    char author[SLEN];
};

// void print_books(const struct book books[], int n);
void print_books(const struct book* book, int n);

int main() {
    // struct book my_book[3];
    int n = 3;
    struct book* my_book = (struct book*)malloc(sizeof(struct book) * n);
    if (my_book == NULL) exit(1);
    my_book[0] = (struct book){"The Great Gatsby", "F. Scott Fitzerald"};
    my_book[1] = (struct book){"Hamlet", "William Shakespeare"};
    my_book[2] = (struct book){"The Odyssey", "Homer"};

    print_books(my_book, n);

    free(my_book);

    return 0;
}

// void print_books(const struct book books[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("\"%s\" written by %s.\n", books[i].title, books[i].author);
//     }
// }

void print_books(const struct book* book, int n) {
    for (int i = 0; i < n; i++) {
        printf("Book %d : \"%s\" written by %s\n", i, book[i].title, book[i].author);
    }
}
