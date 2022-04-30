#include "SimpleList0.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME 20

void read_file(List* plist)
{
    char filename[FILENAME];
    printf("Please input filename to open.\n>> ");
    if (scanf("%[^\n]%*c", filename) != 1) 
    {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }
    

    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error : Cannot open file.\n");
        exit(1);
    }
    
    unsigned int num;
    if (fscanf(file, "%d%*c", &num) != 1)
    {
        printf("Wrong file format.\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) 
    {
        Item new_item;

        if (fscanf(file, "%[^\n]%*c", new_item.title) != 1 ||
            fscanf(file, "%f%*c", &new_item.rating) != 1)
        {
            printf("Error : Wrong file format.\n");
            exit(1);
        }

        AddItem(new_item, plist);
    }

    fclose(file);

    printf("%d items have been read from the file.\n\n", num);
}

unsigned int count_items(const List* plist)
{
    return CountItems(plist);
}

void write_an_item(FILE* const file, const Item item) 
{
    fprintf(file, "%s\n", item.title);
    fprintf(file, "%.1f\n", item.rating);
}

void write_file(const List* const plist) 
{
    char filename[FILENAME];

    printf("Please input filename to write and press enter.\n>> ");
    if (scanf("%[^\n]%*c", filename) != 1)
    {
        printf("Wrong input. Terminating.\n");
        exit(1);
    }

    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error : Cannot open file.\n");
        exit(1);
    }

    unsigned int num = count_items(plist);

    fprintf(file, "%d\n", num);

    unsigned int count = WriteAllItems(file, plist, &write_an_item);
    
    assert(count == num);

    fclose(file);

    printf("%d items have been saved to the file.\n", count);
}

int input_int() 
{
    int input;

    while (1) 
    {
        if (scanf("%d%*c", &input) == 1) return input;
        else
        {
            printf("Please input an integer and press enter.\nTry Again.\n");
            while(getchar() != '\n') continue;
        }
    }
}

int input_menu() 
{
    while (1)
    {
        printf("Please select an option land press enter.\n");
        printf("1. Print all items \t2. Print an item.\n");
        printf("3. Edit an item \t4. Add an item\n");
        printf("5. Insert an item \t6. Delete an item\n");
        printf("7. Delete all items \t8. Save as\n");
        printf("9. Search by name \t10. Quit\n>> ");

        int input = input_int();

        if (input >= 1 && input <= 10) return input;
        else
            printf("Please input a number between 1 ~ 10.\n>>");
    }
}

void print_an_item(Item item) 
{
    printf("\"%s\", %.1f\n", item.title, item.rating);
}

void print_all(const List* plist) 
{
    PrintAllItems(plist, &print_an_item);
}

void find_and_print_an_item(const List* plist) 
{
    printf("Please input the index of item to print.\n>> ");
    int index = input_int();

    Item* pitem;
    const bool is_found = FindByIndex(plist, index, &pitem);

    if (is_found)
    {
        printf("%d : ", index);
        print_an_item(*pitem);
    }
    else
        printf("Invalid item.\n\n");
}

void edit_an_item(List* plist)
{
    printf("Please input the index to edit.\n>> ");
    unsigned int index = input_int();

    Item* pitem;
    const bool is_found = FindByIndex(plist, index, &pitem);

    if (is_found)
    {
        printf("%d : ", index);
        print_an_item(*pitem);

        Item new_item;
        printf("Please input new title and press enter.\n>> ");
        int f = scanf("%[^\n]%*c", new_item.title);
        printf("Please input new rating and press enter.\n>> ");
        f = scanf("%f%*c", &new_item.rating);

        *pitem = new_item;

        printf("%d : ", index);
        print_an_item(*pitem);
    }
    else
        printf("Invalid item.\n\n");
}

void add_an_item(List* plist)
{
    Item new_item;

    printf("Please input title and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_item.title);
    printf("Please input rating and press enter.\n>> ");
    f = scanf("%f%*c", &new_item.rating);
    
    const bool flag = AddItem(new_item, plist);

    if (flag == true) 
        printf("1 item has been added to list.\n\n");
    else    
        printf("Can't add the item.\n");
}

void insert_an_item(List* plist)
{
    printf("Please input the index to insert.\n>> ");
    unsigned int index = input_int();

    unsigned int num_movies = CountItems(plist);

    if (index < 0 || index >= num_movies)
    {
        printf("Please input a number between 0 ~ %d.\n\n", num_movies - 1);
        return;
    }

    Item* pitem;
    const bool flag = FindByIndex(plist, index, &pitem);

    if (flag == false) 
    {
        printf("Invalid index.\n\n");
        return;
    }

    Item new_item;
    printf("Please input title of new item and press enter.\n>> ");
    int f = scanf("%[^\n]%*c", new_item.title);
    printf("Please input rating of new item and press enter.\n>> ");
    f = scanf("%f%*c", &new_item.rating);

    InsertByIndex(plist, new_item, index);

    printf("%d : ", index);
    print_an_item(new_item);
}

int main() 
{
    List movie_list;

    InitializeList(&movie_list);

    // read file
    read_file(&movie_list);

    while (1)
    {
        printf("\n");
        unsigned int user_input = input_menu();

        switch(user_input) 
        {
            case 1 :
                print_all(&movie_list);
                break;
            case 2 :
                // print an item
                find_and_print_an_item(&movie_list);
                break;
            case 3 :
                // edit an item
                edit_an_item(&movie_list);
                break;
            case 4 :
                // add an item
                add_an_item(&movie_list);
                break;
            case 5 :
                // insert an item
                insert_an_item(&movie_list);
                break;
            case 6 :
                // delete an item
                break;
            case 7 :
                // delete all items
                break;
            case 8 :
                write_file(&movie_list);
                break;
            case 9 :
                // search item by name
                break;
            case 10 :
                // close file, memory return
                printf("Bye!\n");
                exit(0);
            default :
                printf("%d is not implemented.\n", user_input);
        }
    }

    //close file, memory return.

    return 0;
}