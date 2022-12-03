#include "stack.h"
#include "canary_protection.h"

#include <stdio.h>

// TODO: no difference between main and tests, therefore main is redundant!

int main()
{
    Stack stk = {};
    
    stack_ctor(&stk, 5);
    stack_print(&stk);
    stack_push(&stk, 1);
    stack_print(&stk);
    int return_val;
    stack_pop(&stk, &return_val);
    stack_print(&stk);
    stack_push(&stk, 3);
    stack_print(&stk);
    stack_push(&stk, 5);
    stack_print(&stk);
    stack_push(&stk, 6);
    stack_print(&stk);
    stack_push(&stk, 1);
    stack_print(&stk);
    stack_push(&stk, 2);
    stack_print(&stk);

    stack_pop(&stk, &return_val);
    printf("==================> %d\n", return_val);

    stack_push(&stk, 9);
    stack_print(&stk);
    stack_push(&stk, 10);
    stack_print(&stk);
    stack_push(&stk, 10);
    stack_print(&stk);
    stack_dtor(&stk);

    return SUCCESS;
}
