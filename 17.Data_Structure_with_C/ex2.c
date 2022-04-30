#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define TSIZE 45

struct movie {
    char title[TSIZE];
    float rating;
};

typedef struct movie Item;

typedef struct node {
    Item item;
    struct node* next;
} Node;

typedef struct list {
    Node* head;     // head pointer
    int size;       // 임의. number of items.
} List;


/* Reading file */
// List는 구조체이기 때문에 함수 매개변수로 넘겨줄때 포인터로 넘겨주지 않으면 메모리가 낭비된다.
void read_file(List* plist) {
    char filename[TSIZE];
    
    printf("Please input filename to read and press enter.\n>> ");
    if (scanf("%[^\n]%*c", filename) != 1) {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error : Cannot open file.\n");
        exit(1);
    }

    int num;
    if (fscanf(file, "%d%*c", &num) != 1) {
        printf("Wrong file format.\n");
        exit(1);
    }

    printf("%d items have been read from the file.\n\n", num);
}

int input_int() {
    int input;
    
    while (1) {
        if (scanf("%d%*c", &input) == 1) return input;
        else {
            printf("Please input an integer and press enter.\nTry again.\n");
            while(getchar() != '\n') continue;
        }
    }
}

int input_menu() {
    while (1) {
        printf("Please select an option and press enter.\n");
        printf("1. Print all items \t2. Print an item\n");
        printf("3. Edit an item \t4. Add an item\n");
        printf("5. Insert an item \t6. Delete an item\n");
        printf("7. Delete all items \t8. Save file\n");
        printf("9. Search by name \t10. Quit\n>> ");

        int input = input_int();

        if (input >= 1 && input <= 10) return input;
        else 
            printf("Please input a number between 1 ~ 10\n");        
    }
}

int main() {
    List movie_list;


    read_file(&movie_list);
    
    while (1) {
        printf("\n");

        int user_choice = input_menu();

        switch(user_choice) {
            case 1 :
                // print_all(&movie_list);
                break;
            case 2 :
                // find_and_print_an_item(&movie_list);
                break;
            case 3 :
                // edit_an_item(&movie_list);
                break;
            case 4 :
                // add_an_item(&movie_list);
                break;
            case 5 :
                // insert_an_item(&movie_list);
                break;
            case 6 :
                // delete_an_item(&movie_list);
                break;
            case 7 :
                // delete_all_items(&movie_list);
                break;
            case 8 :
                // write_file(&movie_list);
                break;
            case 9 :
                // search_by_name(&movie_list);
                break;
            case 10 :
                printf("Bye!.\n");
                // delete_all_items(&movie_list);
                exit(0);
            default :
                printf("%d is not implemented.\n", user_choice);
        }
    }


    return 0;
}
