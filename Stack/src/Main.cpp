#include "stack.h"

int main()
{
    Stack stk = {};

    stack_ctor(&stk, 5);

    stack_push(&stk, 1);
    stack_pop(&stk);
    stack_push(&stk, 3);
    stack_push(&stk, 5);
    stack_push(&stk, 6);
    stack_push(&stk, 1);
    stack_push(&stk, 2);
    stack_push(&stk, 9);

    stack_print(&stk);

    stack_dtor(&stk);

    return SUCCESS;
}
