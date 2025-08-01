#include "stack.h"

void Init_Stack(Stack *stack, int size)
{
    stack->items = (int *)malloc(sizeof(int)*size);
    stack->size = size;
    stack->top = -1;
}

bool IsFull(Stack stack)
{
    if(stack.top == stack.size - 1)
    {
        printf("Stack Is Full!\n");
        return true;
    }
    return false;
}

bool IsEmpty(Stack stack)
{
    if(stack.top == -1)
    {
        printf("Stack Is Empty!\n");
        return true;
    }
    return false;
}

void Push(Stack *stack, int data)
{
    if(IsFull(*stack) == false)
    {
        stack->top++;
        stack->items[stack->top] = data;
        printf("Add %d\n", stack->items[stack->top]);
    }
}

int Pop(Stack *stack)
{
    if(IsEmpty(*stack) == false)
    {
        int data = stack->items[stack->top];
        stack->items[stack->top--];
        return data;
    }
    else return -1;
}

int Top(Stack stack)
{
    if(IsEmpty(stack) == true) return -1;
    else
    {
        return stack.items[stack.top];
    }
}

void FreeStack(Stack *stack)
{
    if(stack->items != NULL){
        free(stack->items);
        stack->items = NULL;
    }
    stack->size = 0;
    stack->top = -1;
}