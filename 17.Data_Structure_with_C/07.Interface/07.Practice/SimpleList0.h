#include <stdio.h>
#include <stdbool.h>

#define TSIZE 30

typedef struct movie {
    char title[TSIZE];
    float rating;
} Item;

typedef struct node {
    Item item;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} List;

void InitializeList(List* plist);
bool AddItem(Item item, List* plist);
unsigned int CountItems(const List* plist);
unsigned int WriteAllItems(FILE* file, const List* plist, void(*write_an_item_func)(FILE* const file, const Item item));
unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item));

bool FindByIndex(const List* plist, unsigned int index, Item** item);
void InsertByIndex(List* plist, Item item, unsigned int index);