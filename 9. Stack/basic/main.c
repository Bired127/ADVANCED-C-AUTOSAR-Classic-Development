#include "stack.h"

int main()
{
    Stack stack1;
    int size = 5;
    Init_Stack(&stack1, size);

    Push(&stack1, 2);
    Push(&stack1, 3);
    Push(&stack1, 8);
    Push(&stack1, 4);
    Push(&stack1, 5);
    Push(&stack1, 5);
}
