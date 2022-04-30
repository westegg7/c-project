#include "SimpleList.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ReadFromFile(List* plist, const char* filename, bool (*read_an_item_func)(FILE* file, Item* Item)) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Cannot open file.\n\n");
        exit(1);
    }

    int n_member;
    if (fscanf(file, "%d%*c", &n_member) != 1)
    {
        printf("Error : Wrong file format.\n");
        exit(1);
    }

    for (int i = 0; i < n_member; i++) 
    {
        Item new_item;

        const bool flag = read_an_item_func(file, &new_item);

        if (flag == false)
        {
            printf("Error : wrong file format.\n");
            exit(1);
        }
        else
            AddItem(new_item, plist);
    }

    fclose(file);

    return n_member;
}

unsigned int FindAndRun(const List* plist, Item item_to_find, 
    bool (*compare_func)(Item a, Item b), void (*func_run)(Item item)) 
{
    Node* pnode = plist->head;
    int count = 0;

    while (pnode != NULL) 
    {
        if (compare_func(pnode->item, item_to_find) == true) 
            func_run(pnode->item);
        pnode = pnode->next;
        count++;
    }

    return count;
}

static void CopyToNode(Item item, Node* pnode) {
    pnode->item = item;
}

void InitializeList(List* plist) {
    plist->head = NULL;
}

bool IsEmpty(const List* plist) {
    if (plist->head == NULL)
        return true;
    else   
        return false;
}

bool IsFull(const List* plist) {
    Node* pt;
    bool full;

    pt = (Node*)malloc(sizeof(Node));
    if (pt == NULL) 
        full = true;
    else
        full = false;
    
    free(pt);

    return full;
}

unsigned int CountItems(const List* plist) {
    unsigned int count = 0;

    Node* pnode = plist->head;

    while (pnode != NULL) {
        count++;
        pnode = pnode->next;
    }

    return count;
}

bool InsertItemFront(Item item, List* plist) {
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("malloc failed.\n");
        return false;
    }
    CopyToNode(item, new_node);

    Node* temp = plist->head;
    plist->head = new_node;
    new_node->next = temp;

    return true;
}

bool AppendItem(Item item, Node* prev) {
    Node* new_item;
    new_item = (Node*)malloc(sizeof(Node));
    if (new_item == NULL) {
        printf("malloc failed.\n");
        return false;
    }

    CopyToNode(item, new_item);
    Node* temp = prev->next;
    prev->next = new_item;
    new_item->next = temp;

    return true;
}

unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Item item)) {
    Node* pnode = plist->head;
    unsigned int count = 0;
    
    while (pnode != NULL) {
        (*write_an_item_func)(file, pnode->item);
        pnode = pnode->next;
        count++;
    }

    return count;
}

bool AddItem(Item item, List* plist) {
    Node* new_node;
    Node* search = plist->head;

    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("malloc failed.\n");
        return false;
    }

    CopyToNode(item, new_node);

    new_node->next = NULL;

    if (search == NULL) {
        plist->head = new_node;
    } else {
        while (search->next != NULL) 
            search = search->next;
        search->next = new_node;
    }

    return true;
}

unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item)) {
    Node* pnode = plist->head;
    unsigned int count = 0;

    while (pnode != NULL) {
        printf("%d : ", count);     // index의 출력이 필요없다면 Traverse 함수를 쓰면 된다.
        (*print_an_item_func)(pnode->item);

        pnode = pnode->next;
        count++;
    }

    return count;
}

void Traverse(const List* plist, void (*pfun)(Item item)) {
    Node* pnode = plist->head;

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

bool FindItemByIndex(const List* plist, const int index, Item** item) {
    Node* pnode = plist->head;      /* set to start of list */

    int count = 0;

    while (pnode != NULL) {
        if (index == count) 
            break;
        
        pnode = pnode->next;
        count++;
    }
    if (pnode == NULL) 
        return false;
    else {
        *item = &pnode->item;       // !중요.  찾은 아이템을 간단히 출력하기 위해서
        return true;
    }
}

Node* FindNodeByIndex(const List* plist, const int index) {
    Node* pnode = plist->head;

    unsigned int count = 0;
    while (pnode != NULL) {
        if (index == count) break;

        pnode = pnode->next;
        count++;
    }
    
    return pnode;
}

void InsertByIndex(Item item, List* plist, int index) {
    Node* prev = FindNodeByIndex(plist, index - 1);

    if (prev == NULL)   // when index is 0.
        InsertItemFront(item, plist);
    else
        AppendItem(item, prev);

}

void RemoveFirstItem(List* plist) {
    Node* temp = NULL;
    if (plist->head != NULL) 
        temp = plist->head->next;
    free(plist->head);
    plist->head = temp;
}

void RemoveNextItem(Node* prev) {
    Node* temp = NULL;
    if (prev->next == NULL) 
        temp = NULL;
    else
        temp = prev->next->next;
    free(prev->next);
    prev->next = temp;
}

void RemoveByIndex(List* plist, int index) {
    Node* prev = FindNodeByIndex(plist, index - 1);

    if (prev == NULL)
        RemoveFirstItem(plist);
    else
        RemoveNextItem(prev);
}

unsigned int ClearList(List* plist) {
    Node* pnode = plist->head;
    Node* temp = NULL;

    unsigned int count = 0;
    while (pnode != NULL) {
        temp = pnode->next;
        free(pnode);
        pnode = temp;
        count++;
    }

    plist->head = NULL;

    return count;
}

bool Find(const List* plist, Item item_to_find, int* index_found, Item* item_found, bool (*compare_func)(Item a, Item b)) {
    Node* pnode = plist->head;

    if (pnode == NULL) {
        printf("There's No item.\n");
        return false;
    }
    
    int count = 0;
    while(pnode != NULL) {
        if (compare_func(pnode->item, item_to_find) == true) {
            *item_found = pnode->item;
            *index_found = count;
            return true;
        }

        pnode = pnode->next;
        count++;
    }

    return false;
}
