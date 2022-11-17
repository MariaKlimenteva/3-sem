#include "stack.h"
#include "canary_protection.h"

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
    stack_push(&stk, 9);

    stack_print(&stk);

    stack_push(&stk, 10);
    stack_push(&stk, 10);

    stack_dtor(&stk);

    return SUCCESS;
}
