#include "element.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 5

typedef struct stack
{
    element items[MAX_STACK_SIZE];
    int top;
} Stack;

void Initialize(Stack* stack);
bool IsFull(Stack* stack);
bool IsEmpty(Stack* stack);
void Push(Stack* stack, element item);
element Pop(Stack* stack);