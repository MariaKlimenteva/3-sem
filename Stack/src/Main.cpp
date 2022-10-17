#include "stack.h"

int main()
{
    Stack stk = {};

    stack_ctor(&stk, 5);

    stack_push(&stk, 1);
    stack_pop(&stk);

    stack_print(&stk);

    stack_dtor(&stk);

    return SUCCESS;
}
