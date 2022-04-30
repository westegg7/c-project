#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define TITLE 30
#define FILENAME 20

struct movie
{
    char title[TITLE];
    float rating;
    struct movie *next;
};

typedef struct movie *p_movie;

void read_file(p_movie *p_head);
unsigned int count_items(const p_movie head);
void write_file(const p_movie head);
int input_int();
int input_menu();
void print_all(const p_movie head);
void print_an_item(const p_movie head);
void edit_an_item(p_movie head);
void add_an_item(p_movie *p_head);
void insert_an_item(p_movie *p_head);
void delete_an_item(p_movie *p_head);
void delete_all_items(p_movie *p_head);
void search_by_name(const p_movie head);

int main()
{
    struct movie *movie_list = NULL;

    read_file(&movie_list);

    while (1)
    {
        int user_choice = input_menu();

        switch (user_choice)
        {
        case 1:
            print_all(movie_list);
            break;
        case 2:
            print_an_item(movie_list);
            break;
        case 3:
            edit_an_item(movie_list);
            break;
        case 4:
            add_an_item(&movie_list);
            break;
        case 5:
            insert_an_item(&movie_list);
            break;
        case 6:
            delete_an_item(&movie_list);
            break;
        case 7:
            delete_all_items(&movie_list);
            break;
        case 8:
            write_file(movie_list);
            break;
        case 9:
            search_by_name(movie_list);
            break;
        case 10:
            printf("Bye!.\n");
            free(movie_list);
            exit(0);
        default:
            printf("%d is not implemented.\n", user_choice);
        }
    }

    free(movie_list);

    return 0;
}

void read_file(p_movie *p_head)
{
    char filename[FILENAME];

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

    int num;
    if (fscanf(file, "%d%*c", &num) != 1)
    {
        printf("Wrong file format.\n");
        exit(1);
    }

    p_movie pnode = *p_head;

    for (int i = 0; i < num; ++i)
    {
        p_movie new_node = malloc(sizeof(struct movie));
        if (new_node == NULL)
        {
            printf("ERROR : malloc failed.\n");
            exit(1);
        }

        if (fscanf(file, "%[^\n]%*c", new_node->title) != 1 ||
            fscanf(file, "%f%*c", &new_node->rating) != 1)
        {
            printf("ERROR : Wrong File format.\n");
            exit(1);
        }

        if (pnode == NULL)
        {
            *p_head = new_node;
            pnode = new_node;
        }
        else
        {
            // Insert front
            // p_movie temp = (*p_head);
            // *p_head = new_node;
            // new_node->next = temp;

            // Add at the end
            pnode->next = new_node;
            pnode = new_node;
        }
    }

    fclose(file);

    printf("%d items have been read from the file.\n\n", num);
}

unsigned int count_items(const p_movie head)
{
    unsigned int count = 0;
    p_movie pnode = head;

    while (pnode != NULL)
    {
        count += 1;
        pnode = pnode->next;
    }

    return count;
}

void write_file(const p_movie head)
{
    char filename[FILENAME];
    int count = 0;

    printf("Please input filename to write and press enter.\n>> ");
    if (scanf("%[^\n]%*c", filename) != 1)
    {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error : Cannot open file.\n");
        exit(1);
    }

    fprintf(file, "%d\n", (int)count_items(head));

    p_movie pnode = head;

    while (pnode != NULL)
    {
        fprintf(file, "%s\n%.1f\n", pnode->title, pnode->rating);
        pnode = pnode->next;

        count++;
    }

    fclose(file);

    assert(count == (int)count_items(head));

    printf("%d items have been saved to the file.\n", count);
}

int input_int()
{
    int input;

    while (1)
    {
        if (scanf("%d%*c", &input) == 1)
            return input;
        else
        {
            printf("Please input an integer and press enter.\nTry again.\n");
            while (getchar() != '\n')
                continue;
        }
    }
}

int input_menu()
{
    while (1)
    {
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

void print_all(const p_movie head)
{
    p_movie pnode = head;

    int count = 0;
    if (head == NULL)
    {
        printf("No file. Please add some files\n\n");
        return;
    }

    while (pnode != NULL)
    {
        printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);

        pnode = pnode->next;
        count++;
    }
    printf("\n");
}

void print_an_item(const p_movie head)
{
    printf("Input the index of item to print.\n");
    int index = input_int();
    int n_items = (int)count_items(head);

    p_movie pnode = head;

    int count = 0;

    if (index < n_items)
    {
        while (pnode != NULL)
        {
            if (count == index)
                break;

            pnode = pnode->next;
            count++;
        }
    }
    else
    {
        printf("Invalid Item Index.\n\n");
        return;
    }

    printf("%d : \"%s\", %.1f\n\n", count, pnode->title, pnode->rating);
}

void edit_an_item(p_movie head)
{
    printf("Input the index of item to edit.\n");
    int index = input_int();
    int n_items = (int)count_items(head);
    p_movie pnode = head;

    int count = 0;

    if (index >= n_items)
    {
        printf("Invalid item.\n\n");
        return;
    }
    else
    {
        while (pnode != NULL)
        {
            if (count == index)
                break;

            count++;
            pnode = pnode->next;
        }
        printf("%d : \"%s\", %.1f\n\n", index, pnode->title, pnode->rating);
        printf("Input new title and press enter.\n>> ");
        scanf("%[^\n]%*c", pnode->title);
        printf("Input rating and press enter.\n>> ");
        scanf("%f%*c", &pnode->rating);

        printf("%d : \"%s\", %.1f\n\n", index, pnode->title, pnode->rating);
    }
}

void add_an_item(p_movie *p_head)
{
    p_movie pnode = *p_head;

    p_movie new_movie = malloc(sizeof(struct movie));
    if (new_movie == NULL)
    {
        printf("ERROR: malloc failed.\n\n");
        exit(1);
    }
    new_movie->next = NULL;

    printf("Input title and press enter.\n>> ");
    scanf("%[^\n]%*c", new_movie->title);
    printf("Input rating and press enter.\n>> ");
    scanf("%f%*c", &new_movie->rating);

    int count = 0;
    if (*p_head == NULL)
    {
        *p_head = new_movie;
        count++;
    }
    else
    {
        while (pnode->next != NULL)
        {
            pnode = pnode->next;
            count++;
        }
        pnode->next = new_movie;
        count++;
    }

    printf("%d : \"%s\", %.1f\n\n", count, new_movie->title, new_movie->rating);
}

void insert_an_item(p_movie *p_head)
{
    p_movie pnode = *p_head;
    p_movie prev = NULL;

    int n_items = (int)count_items(*p_head);

    printf("Input the index to insert.\n>> ");
    int index = (int)input_int();
    if (index >= n_items)
    {
        printf("Invalid index number.\n\n");
        return;
    }

    int count = 0;
    while (pnode != NULL)
    {
        if (count == index)
            break;

        prev = pnode;
        pnode = pnode->next;
        count++;
    }

    if (pnode == NULL)
    {
        printf("Invalid index number.\n\n");
        return;
    }

    p_movie new_movie = malloc(sizeof(struct movie));
    if (new_movie == NULL)
    {
        printf("ERROR: malloc failed.\n\n");
        exit(1);
    }
    new_movie->next = NULL;

    printf("Input title and press enter.\n>> ");
    scanf("%[^\n]%*c", new_movie->title);
    printf("Input rating and press enter.\n>> ");
    scanf("%f%*c", &new_movie->rating);

    printf("%d : \"%s\", %.1f\n\n", index, new_movie->title, new_movie->rating);

    if (prev == NULL)
    {
        *p_head = new_movie;
    }
    else
    {
        prev->next = new_movie;
    }
    new_movie->next = pnode;
}

int check_delete()
{
    char confirm;

    while (1)
    {
        scanf("%c%*[^\n]%*c", &confirm);

        if (confirm == 'Y' || confirm == 'y')
        {
            break;
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            return 1;
        }
        else
        {
            printf("Please input Y(y) of N(n)\n>> ");
        }
    }
    return 0;
}

void delete_an_item(p_movie *p_head)
{
    printf("Please input the index to delete.\n");

    int index = input_int();

    int count = 0;
    p_movie pnode = *p_head;
    p_movie prev = NULL;

    while (pnode != NULL)
    {
        if (count == index)
            break;

        prev = pnode;
        pnode = pnode->next;
        count++;
    }

    if (pnode == NULL)
    {
        printf("Invalid index number.\n\n");
        return;
    }

    printf("Do you really want to delete %d : \"%s\", %.1f ?? \nY/N >> ", index, pnode->title, pnode->rating);

    if (check_delete()) // 아이템을 삭제할것인지 다시 확인하는 함수. 삭제를 취소할 경우 1을 리턴한다.
        return;

    if (prev == NULL)
    {
        *p_head = pnode->next;
    }
    else
    {
        prev->next = pnode->next;
    }

    free(pnode);
}

void delete_all_items(p_movie *p_head)
{
    printf("Do you really want to delete all items?\n>> ");

    char confirm;
    while (1)
    {
        scanf("%c%*[^\n]%*c", &confirm);

        if (confirm == 'Y' || confirm == 'y')
        {
            break;
        }
        else if (confirm == 'N' || confirm == 'n')
        {
            return;
        }
        else
        {
            printf("Please input Y(y) of N(n)\n>> ");
        }
    }

    int count = 0;

    p_movie search = *p_head;

    if (search == NULL)
    {
        printf("Nothing to delete.\n\n");
        return;
    }

    p_movie temp = NULL;

    while (*p_head != NULL)
    {
        temp = (*p_head)->next;
        free(*p_head);
        *p_head = temp;
        count++;
    }

    printf("%d items have been deleted.\n\n", count);
}

void search_by_name(const p_movie head)
{
    char keyword[20];
    int index_found;
    bool is_found = false;

    printf("Please input a keyword.\n>> ");
    scanf("%[^\n]%*c", keyword);

    p_movie pnode = head;

    int count = 0;
    while (pnode != NULL)
    {
        if (strstr(pnode->title, keyword) != NULL)
        {
            index_found = count;
            printf("%d : \"%s\", %.1f\n\n", index_found, pnode->title, pnode->rating);
            is_found = true;
        }

        pnode = pnode->next;
        count++;
    }

    if (is_found == false)
    {
        printf("No result for %s.\n\n", keyword);
    }
}
