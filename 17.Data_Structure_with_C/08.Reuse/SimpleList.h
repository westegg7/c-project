#include <stdio.h>
#include <stdbool.h>

#define TSIZE 45

struct member {
    char name[TSIZE];
    int year;
};

typedef struct member Item;

typedef struct node {
    Item item;
    struct node* next;
} Node;

typedef struct list {
    Node* head;     // head pointer
    int size;       // 임의. number of items.
} List;

int ReadFromFile(List* plist, const char* filename, bool (*read_an_item_func)(FILE* file, Item* Item));
unsigned int FindAndRun(const List* plist, Item item_to_find, bool (*compare_func)(Item a, Item b), void (*func_run)(Item item));

void InitializeList(List* plist);
bool IsEmpty(const List* plist);    // Not used in this example
bool IsFull(const List* plist);     // Not used in this example
bool AddItem(Item item, List* plist);
void InsertByIndex(Item item, List* plist, int index);
void RemoveByIndex(List* plist, int index);
bool InsertItemFront(Item item, List* plist);
bool Find(const List* plist, Item item_to_find, int* index, Item* item_found, bool (*compare_func)(Item a, Item b));

unsigned int CountItems(const List* plist);
unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item));
unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Item item));

void Traverse(const List* plist, void (*pfun)(Item item));
unsigned int ClearList(List* plist);

bool FindItemByIndex(const List* plist, const int index, Item** item);
void RemoveFirstItem(List* plist);
