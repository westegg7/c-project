#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3

char* s_gets(char* st, int n) {
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}

struct Books {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main() {
    struct Books library[MAX_BOOKS];    // array of book structures

    int count = 0;

    while (1) {
        printf("Input a book title or press [Enter] to stop.\n>>");
        if (s_gets(library[count].title, MAX_TITLE) == NULL) 
            break;
        if (library[count].title[0] == '\0')
            break;
        
        printf("Input the author.\n>>");
        s_gets(library[count].author, MAX_AUTHOR);

        printf("Input the price.\n>>");
        scanf("%f", &library[count].price);
        while(getchar() != '\n')
            continue;   // clear input line

        count++;

        if (count == MAX_BOOKS)
            break;
    }

    if (count > 0) {
        printf("\nThe list of books:\n");
        for (int index = 0; index < count; index++) {
            printf("\"%s\" written by %s : $%.1f\n", library[index].title, library[index].author, library[index].price);
        }
    } else 
        printf("No books to show. \n");

    return 0;
}