#include "stack.h"
#include "stack_log.h"
#include "log.h"
#include "canary_protection.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>

void stack_ctor (struct Stack* stk, int capacity)
{ 
    stk->capacity = capacity; // TODO: named designators?
    stk->size = 0;

    // *stk = (Stack) { .capacity = ..., .size = ... };
    // This is not actually a named designator, it's a compound statement.

    // Because in this case designator only works by C++ rules:
    // *stk = { .capacity = ..., .size = ... }; // Valid in C++, invalid in C
    //        ^ this is a named designator

    memory_allocation(stk);

    add_protection_(stk);
    check_canaries_(stk);
    log("Stack was create, capacity is: %d, size is: %d\n", stk->capacity, stk->size);
}

void stack_dtor(struct Stack* stk)
{
    free(stk->data);
    stk->data = NULL;
    stk->capacity = -1;
    
    // TODO: designator? E.g.
    // *stk = { .data = NULL, .capacity = -1 };

    // I would even do:
    // *stk = {};
}

int stack_push(struct Stack* stk, int value)
{   
    if(stk == NULL)
    {
        return NULL_STACK_PTR;
    }

    if(stk->size == stk->capacity)
    { 
        int new_capacity = stk->capacity * 2;
        int error = stack_resize(stk, new_capacity); // TODO: stack resize can fail, you should check!
        if(error == NOT_ENOUGH_MEMORY) return error;
//      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TODO: common pattern, think about extracting (propagate_error)
    }

    stack_get_base_ptr(stk)[stk->size] = value;
    stk->size++;

    check_canaries_(stk);

    log("You pushed %d in stack, size is: %d, capacity is: %d\n", value, stk->size, stk->capacity);

    return SUCCESS;
}

int stack_resize(struct Stack* stk, int new_capacity) 
{
    check_canaries_(stk);

    stk->capacity = new_capacity;

    
    // memory_allocation(stk);
    #ifndef NCANARY_PROT
    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity + NUMBER_OF_CANARIES));
    #else  //                                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TODO: extract
    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity)); // TODO: minimize effect of ifndef
    #endif // TODO: why have you extracted calloc, not me!!?

    // note: there's a way to join invokations of both calloc and realloc (though, it's not portable i think)
    //       look up what realloc does when you provide NULL pointer as its argument buffer, and think
    //       if you can use it for your advantage.

    //      (i think you will be able to call resize from constructor)

    if(stk->data == NULL)
    {
        return NOT_ENOUGH_MEMORY;
    }
    else
    {
        add_protection_(stk);
        return SUCCESS;
    }
}

int stack_pop(struct Stack* stk, int* return_val)
{
    check_canaries_(stk);

    if(stk->size < 1)
    {
        log("The stack is empty\n");
        return EMPTY_STACK_ERROR;
    }

    *return_val = stack_get_base_ptr(stk)[stk->size - 1]; 
    stk->size--;


    log("You pulled an element from the stack, the value is equal to %d\nNew size is: %d\n", *return_val, stk->size);

    return SUCCESS;
}

void stack_print(struct Stack* stk) 
{
    log("\n\nThe stack now looks like this:\n"); // TODO: its very weird to disable prints in *_print function

    #ifndef NCANARY_PROT
    for(int i = 0; i < stk->capacity + NUMBER_OF_CANARIES; i++)
    { //               ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ extract
        log("|%d", stk->data[i]);
    }
    #else
    for(int i = 0; i < stk->capacity; i++)
    {
        log("|%d", stk->data[i]);
    }
    #endif
    
    log("|\n\n");
}

void memory_allocation(struct Stack* stk) // TODO: inconsistently extracted
{
    #ifndef NCANARY_PROT
    stk->data = (int*) calloc(stk->capacity + NUMBER_OF_CANARIES, sizeof(int));
    #else                 //  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ same thing, extract
    stk->data = (int*) calloc(stk->capacity, sizeof(int));
    #endif
}