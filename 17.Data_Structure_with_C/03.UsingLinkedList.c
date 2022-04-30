#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct movie
{
    char title[TSIZE];
    float rating;
    struct movie *next;
};

typedef struct movie *p_movie;

void print_all(struct movie *head)
{
    printf("-------------------------------\n");
    printf("Head address = %zd\n", (size_t)head);
    struct movie *search = head;
    while (search != NULL)
    {
        printf("%zd \"%s\" %.1f %zd\n", (size_t)search, search->title,
               search->rating, (size_t)search->next);
        search = search->next;
    }
}

int main()
{
    p_movie head = NULL;

    /* First Node */
    p_movie new_node = malloc(sizeof(struct movie));
    if (new_node == NULL)
    {
        printf("ERROR: malloc failed.");
        exit(1);
    }
    strcpy(new_node->title, "Avatar");
    new_node->rating = 9.5f;
    new_node->next = NULL;

    if (head == NULL)
        head = new_node; // First node
    // else {} // insert or add back

    /* Second Node */
    new_node = malloc(sizeof(struct movie));
    if (new_node == NULL)
    {
        printf("ERROR: malloc failed.");
        exit(1);
    }
    strcpy(new_node->title, "Aladdin");
    new_node->rating = 9.0f;
    new_node->next = NULL;

    // Add front
    p_movie temp = head;
    head = new_node;
    new_node->next = temp;

    print_all(head);

    /* Third Node */
    new_node = malloc(sizeof(struct movie));
    if (new_node == NULL)
    {
        printf("ERROR: malloc failed.");
        exit(1);
    }

    strcpy(new_node->title, "Arrival");
    new_node->rating = 9.4f;
    new_node->next = NULL;

    // Add back
    p_movie search = head;
    while (search->next != NULL)
    {
        search = search->next;
    }
    search->next = new_node;

    print_all(head);

    /* Find and delete item */
    search = head;
    p_movie prev = NULL;

    int count = 0;
    while (search != NULL)
    {
        if (strcmp(search->title, "Aladdin") == 0)
            break;

        prev = search;
        search = search->next;
        count++;
    }

    if (search == NULL)
    {
        printf("Wrong title.\n");
        return 0;
    }
    if (prev == NULL)
        head = search->next;
    else
        prev->next = search->next;
    free(search);

    print_all(head);

    return 0;
}
