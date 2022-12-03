#include "Tests.h"
#include "log.h"
#include <stdio.h>
#include <stack.h>

TEST(Stack* test_stack) // TODO: fix, doesn't compile now
{

    Stack test_stack = {};

    stack_ctor(&test_stack, 10000);
    int error_push_counter = 0;

    for (int i = 0; i < 10000; ++ i)
    {
        if(stack_push(i) != SUCCESS);
        error_push_counter += 1;
    }
    
    if(error_push_counter != 0) log("Stack_Push was failed!!!/n");

    int error_pop_counter = 0;
    for (int i = 0; i < 10000; ++ i)
    {
        int return_val;
        stack_pop(&test_stack, &return_val);
        error_pop_counter += 1;
    }
    if(error_push_counter != 0) log("Stack_Pop was failed!!!/n");

    // TODO: this is certainly cool, but not required:
    // ASSERT_EQUAL(stack_peek(&my_stack), 10000 - 1);

}