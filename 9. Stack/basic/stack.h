#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int *items;
    int size;
    int top;
}Stack;

void Init_Stack(Stack *stack, int size);

bool IsFull(Stack stack);

bool IsEmpty(Stack stack);

void Push(Stack *stack, int data);

int Pop(Stack *stack);

int Top(Stack stack);

void FreeStack(Stack *stack);

#endif