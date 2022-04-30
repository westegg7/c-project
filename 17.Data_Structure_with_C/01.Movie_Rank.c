#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TITLE 30
#define FILENAME 20

struct movie
{
    char title[TITLE];
    float rating;
};

void read_file(struct movie** ptr_movie_list, int *ptr_n_items);
void write_file(struct movie* movie_list, int n_items);
int input_int();
int input_menu();
void print_all(struct movie* movie_list, int n_items);
void print_an_item(struct movie* movie_list, int n_items);
void edit_an_item(struct movie* movie_list, int n_items);
void add_an_item(struct movie** ptr_movie_list, int* ptr_n_items);
void insert_an_item(struct movie** ptr_movie_list, int* ptr_n_items);
void delete_an_item(struct movie** ptr_movie_list, int* ptr_n_items);
void search_by_name(struct movie* movie_list, int n_items);

int main()
{
    struct movie *movie_list = NULL;
    int n_items = 0;

    read_file(&movie_list, &n_items);

    while (1)
    {
        int user_choice = input_menu();

        switch (user_choice)
        {
        case 1:
            print_all(movie_list, n_items);
            break;
        case 2:
            print_an_item(movie_list, n_items);
            break;
        case 3:
            edit_an_item(movie_list, n_items);
            break;
        case 4:
            add_an_item(&movie_list, &n_items);
            break;
        case 5:
            insert_an_item(&movie_list, &n_items);
            break;
        case 6:
            delete_an_item(&movie_list, &n_items);
            break;
        case 7:
            n_items = 0;
            break;
        case 8:
            write_file(movie_list, n_items);
            break;
        case 9:
            search_by_name(movie_list, n_items);
            break;
        case 10:
            printf("Bye!.\n");
            free(movie_list);
            n_items = 0;
            exit(0);
        default:
            printf("%d is not implemented.\n", user_choice);
        }
    }

    free(movie_list);
    n_items = 0;

    return 0;
}

void read_file(struct movie **ptr_movie_list, int *ptr_n_items)
{
    char filename[FILENAME];
    int flag = 0;

    printf("Please input filename to read and press enter.\n>> ");
    if (scanf("%[^\n]%*c", filename) != 1)
    {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error : Cannot open file.\n");
        exit(1);
    }

    int num = 0;
    if (fscanf(file, "%d%*c", &num) != 1)
    {
        printf("Wrong file format.\n");
        exit(1);
    }

    *ptr_movie_list = (struct movie *)malloc(sizeof(struct movie) * num);
    if (*ptr_movie_list == NULL)
    {
        printf("malloc failed.\n");
        exit(1);
    }

    for (int i = 0; i < num; i++)
    {
        flag = fscanf(file, "%[^\n]%*c%f%*c", (*ptr_movie_list)[i].title, &(*ptr_movie_list)[i].rating);
        if (flag != 2)
        {
            printf("Error : Wrong file format.\n");
            exit(1);
        }
    }

    *ptr_n_items = num;

    fclose(file);

    printf("\n%d item(s) have been read from the file.\n", *ptr_n_items);
}

void write_file(struct movie *movie_list, int n_items) {
    char new_file_name[FILENAME];

    printf("Please input filename to write and press enter.\n>> ");
    if (scanf("%[^\n]%*c", new_file_name) != 1) {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }

    FILE* file = fopen(new_file_name, "w");
    if (file == NULL) {
        printf("Error : Cannot open file.\n");
        exit(1);
    }

    fprintf(file, "%d\n", n_items);
    for (int i = 0; i < n_items; i++) {
        fprintf(file, "%s\n%.1f\n", movie_list[i].title, movie_list[i].rating);
    }

    fclose(file);

    printf("%d items have been saved as %s\n", n_items, new_file_name);
}

int input_int() {
    int input;

    while (1) {
        if (scanf("%d%*c", &input) == 1)
            return input;
        else {
            printf("Please input an integer and press enter.\n Try again.\n");
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

        if (input >= 1 && input <= 10)
            return input;
        else
            printf("Please input a number between 1 ~ 10\n");
    }
}

void print_all(struct movie* movie_list, int n_items) {
    if (n_items == 0) {
        printf("No item.\n\n");
        return;
    }
    for (int i = 0; i < n_items; i++) {
        printf("%d : \"%s\", %.1f\n", i, movie_list[i].title, movie_list[i].rating);
    }
    printf("\n");
}

void print_an_item(struct movie* movie_list, int n_items) {
    printf("Input the index of item to print.\n");
    int index = input_int();
    if (index < n_items) 
        printf("%d : \"%s\", %.1f\n\n", index, movie_list[index].title, movie_list[index].rating);
    else 
        printf("Invalid index\n");
}

void edit_an_item(struct movie* movie_list, int n_items) {
    printf("Input the index of item to edit.\n");
    int index = input_int();
    if (index < n_items) {
        printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
        
        printf("Input new title and press enter.\n>> ");
        scanf("%[^\n]%*c", movie_list[index].title);
        printf("Input rating and press enter.\n>> ");
        scanf("%f%*c", &movie_list[index].rating);

        printf("%d : \"%s\", %.1f\n\n", index, movie_list[index].title, movie_list[index].rating);
    }
    else
        printf("Invalid item.\n\n");
}

void add_an_item(struct movie** ptr_movie_list, int* ptr_n_items) {
    /* Resizing allocated memory */
    struct movie* temp = *ptr_movie_list;
    *ptr_movie_list = (struct movie*)malloc(sizeof(struct movie) * (*ptr_n_items + 1));
    if (*ptr_movie_list == NULL) {
        printf("malloc failed.\n");
        exit(1);
    }

    memcpy(*ptr_movie_list, temp, sizeof(struct movie) * (*ptr_n_items));
    free(temp);

    const int index = *ptr_n_items;

    printf("Input title and press enter.\n>> ");
    scanf("%[^\n]%*c", (*ptr_movie_list)[index].title);
    printf("Input rating and press enter.\n>> ");
    scanf("%f%*c", &(*ptr_movie_list)[index].rating);
    
    printf("%d : \"%s\", %.1f\n\n", index, (*ptr_movie_list)[index].title, (*ptr_movie_list)[index].rating);

    *ptr_n_items += 1;
}

void insert_an_item(struct movie** ptr_movie_list, int* ptr_n_items) {
    struct movie* temp = *ptr_movie_list;
    *ptr_movie_list = (struct movie*)malloc(sizeof(struct movie) * (*ptr_n_items + 1));
    if (*ptr_movie_list == NULL) {
        printf("malloc failed.\n");
        exit(1);
    }

    memcpy(*ptr_movie_list, temp, sizeof(struct movie) * (*ptr_n_items));
    free(temp);

    printf("Please input the index to insert.\n");
    int index = input_int();
    
    if (index < *ptr_n_items) {
        memmove(&(*ptr_movie_list)[index + 1], &(*ptr_movie_list)[index], sizeof(struct movie*) * (*ptr_n_items - index));
    
        printf("Input title and press enter.\n>> ");
        scanf("%[^\n]%*c", (*ptr_movie_list)[index].title);
        printf("Input rating and press enter.\n>> ");
        scanf("%f%*c", &(*ptr_movie_list)[index].rating);

        printf("%d : \"%s\", %.1f\n\n", index, (*ptr_movie_list)[index].title, (*ptr_movie_list)[index].rating);

        *ptr_n_items += 1;
    }
    else
        printf("Invalid index number.\n\n");
}

void delete_an_item(struct movie** ptr_movie_list, int* ptr_n_items) {
    char confirm;

    printf("Please input the index to delete.\n");

    int index = input_int();

    printf("Do you really want to delete %d : \"%s\", %1.f ?? \nY/N >>", 
    index, (*ptr_movie_list)[index].title, (*ptr_movie_list)[index].rating);

    while (1) {
        scanf("%c%*[^\n]%*c", &confirm);

        if (confirm == 'Y' || confirm == 'y') {
            break;
        } else if (confirm == 'N' || confirm == 'n') {
            return;
        } else {
            printf("Please input Y(y) or N(n)\n>>");
        }
    }

    if (index < *ptr_n_items) {
        memmove(&(*ptr_movie_list)[index], &(*ptr_movie_list)[index + 1], sizeof(struct movie) * (*ptr_n_items = index));
        *ptr_n_items -= 1;
    } else 
        printf("Invalid index number.\n\n");
}

void search_by_name(struct movie* movie_list, int n_items) {
    char keyword[20];
    int index_found;
    bool is_found = false;

    printf("Please input a keyword.\n>> ");
    scanf("%[^\n]%*c", keyword);

    for (int i = 0; i < n_items; ++i) {
        if (strstr(movie_list[i].title, keyword) != NULL) {
            index_found = i;
            printf("%d : \"%s\", %.1f\n\n", index_found, movie_list[index_found].title, movie_list[index_found].rating);
            is_found = true;
        }
    }

    if (is_found == false)
        printf("No result for %s.\n\n", keyword);
}



