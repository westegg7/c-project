#include <stdio.h>
#include "stack.h"

#define WIDTH 7
#define HEIGHT 7

static int map[HEIGHT][WIDTH] = 
{   //0:empty, 1:full
    0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 0,
    0, 1, 0, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 1, 0,
    0, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0
};

void print_map()
{
    for (int j = 0; j < HEIGHT; ++j)
    {
        for (int i = 0; i < WIDTH; ++i)
            printf("%d ", map[j][i]);
        printf("\n");
    }
    printf("\n");
}

element get_element(const int i, const int j)
{
    element new_element;
    new_element.i = i;
    new_element.j = j;
    return new_element;
}

print_stack(const Stack* stack)
{
    printf("Stack : ");
    if (IsEmpty(stack) == true)
        printf("Empty.\n");
    else
        for (int i = 0; i <= stack->top; ++i)
            printf("(%d, %d) ", stack->items[i].i, stack->items[i].j);
    printf("\n");
}

int main() 
{
    print_map();
    



    return 0;
}