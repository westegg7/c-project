#include "SimpleList0.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node* pnode)
{
    pnode->item = item;
}

void InitializeList(List* plist)
{
    plist->head = NULL;
}

bool AddItem(Item item, List* plist)
{
    Node* new_node;
    Node* search = plist->head;

    new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("malloc failed.\n");
        return false;
    }

    CopyToNode(item, new_node);

    new_node->next = NULL;

    if (search == NULL)
        plist->head = new_node;
    else
    {
        while (search->next != NULL)
            search = search->next;
        search->next = new_node;
    }
    
    return true;
}

unsigned int CountItems(const List* plist)
{
    Node* pnode = plist->head;
    unsigned int count = 0;

    if (pnode == NULL) 
        return count;
    else
    {
        while(pnode != NULL)
        {
            count++;
            pnode = pnode->next;
        }
    }
    
    return count;
}

unsigned int WriteAllItems(FILE* file, const List* plist, void (*write_an_item_func)(FILE* const file, const Item item)) 
{
    Node* pnode = plist->head;
    unsigned int count = 0;

    while (pnode != NULL) 
    {
        (*write_an_item_func)(file, pnode->item);
        pnode = pnode->next;
        count++;
    }

    return count;
}

unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item))
{
    Node* pnode = plist->head;
    unsigned int count = 0;

    if (pnode == NULL) 
    {
        printf("There's no item to print.\n\n");
        return count;
    }
    else
    {
        while (pnode != NULL) 
        {
            printf("%d : ", count);
            (*print_an_item_func)(pnode->item);
            pnode = pnode->next;
            count++;
        }
    }

    return count;
}

bool FindByIndex(const List* plist, unsigned int index, Item** item)
{
    Node* pnode = plist->head;

    unsigned int count = 0;

    while (pnode != NULL) 
    {
        if (count == index) break;

        pnode = pnode->next;
        count++;
    }
    if (pnode == NULL)
        return false;
    else
    {
        *item = &pnode->item;
        return true;
    }
}

bool InsertItemFront(List* plist, Item item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error : malloc failed.\n\n");
        return false;
    }
    CopyToNode(item, new_node);

    Node* temp = plist->head;
    plist->head = new_node;
    new_node->next = temp;

    return true;
}

bool AppendItem(Node* prev, Item item)
{
    Node* new_item;
    new_item = (Node*)malloc(sizeof(Node));
    if (new_item == NULL) 
    {
        printf("Error : malloc failed.\n\n");
        return false;
    }

    CopyToNode(item, new_item);
    Node* temp = prev->next;
    prev->next = new_item;
    new_item->next = temp;

    return true;
}

Node* FindNodeByIndex(List* plist, const unsigned int index)
{
    Node* pnode = plist->head;
    unsigned int count = 0;

    while (pnode != NULL)
    {
        if (index == count)
            break;
        pnode = pnode->next;
        count++;
    }

    return pnode;
}

void InsertByIndex(List* plist, Item item, unsigned int index)
{
    Node* prev = FindNodeByIndex(plist, index - 1);
    
    if (prev == NULL) 
        InsertItemFront(plist, item);
    else
        AppendItem(prev, item);
}

