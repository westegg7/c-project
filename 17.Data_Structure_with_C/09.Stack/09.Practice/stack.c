#include "stack.h"
#include <stdio.h>
#include <stdbool.h>



void Initialize(Stack* stack) 
{
    stack->top = -1;
}

bool IsFull(Stack* stack)
{
    if (stack->top >= MAX_STACK_SIZE - 1)
        return true;
    else
        return false;
}

bool IsEmpty(Stack* stack)
{
    if (stack->top == -1)
        return true;
    else    
        return false;
}

void Push(Stack* stack, element item)
{
    if (IsFull(stack) == true)
        printf("Stack is full. Cannot add.\n");
    else
        stack->items[++(stack->top)] = item;
}

element Pop(Stack* stack)
{
    if (IsEmpty(stack) == true)
    {
        printf("Stack is empty. Cannot remove.\n");
        element temp = { -1, };
        return temp;
    }
    return stack->items[(stack->top)--];
}
