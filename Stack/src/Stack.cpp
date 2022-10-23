#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

void stack_ctor (struct Stack* stk, int capacity)
{ 
    stk->capacity = capacity; 
    stk->size = 0;

    stk->data = (int*) calloc(stk->capacity, sizeof(int));

    // TODO: hide printf in logging, so you can turn it off:
    
    //                      ^ created TODO :)

    // TODO: see, simplest logging system:

    #ifndef NDEBUG // you can define it with -DNDEBUG
    #define log("Stack was create, capacity is: %d, size is: %d\n", stk->capacity, stk->size) printf("Stack was create, capacity is: %d, size is: %d\n", stk->capacity, stk->size);
    #else
    #define log(...) ((void) 0)
    #endif

    // TODO: example usage:
    // log("Hello, %s", "world!"); // expands to => printf(...)

    // A bit more elaborate version could be:
    // log(INFO, "Hello, world!")
    //     ^~~~ note: added logging level as first parameter to macro

    // Common levels are: ERROR, WARNING, INFO, TRACE
    // But you can come up with your own!

    // Stack was created
    // ... 10000
    // <=  .............
    // ... 10000
}

void stack_dtor(struct Stack* stk)
{
    free(stk->data); // consider stk->data = NULL; after free?
    //        ^ same thing, consider zeroing pointer to data,
    //          it is useful because it will allow you to call dtor again
    //          without double free

    stk->capacity = -1; //shows, that the stack has already destructed
}

void stack_push(struct Stack* stk, int value)
{ 
    assert(stk->data != NULL); // TODO: what if stk NULL?
    
    if(stk->size >= stk->capacity)
    { 
        stack_resize(stk);
    }
    
    stk->data[stk->size++] = value;
    printf("You pushed %d in stack, size is: %d, capacity is: %d\n", value, stk->size, stk->capacity); // TODO: logging?
}

int stack_resize(struct Stack* stk) 
{
    stk->capacity = stk->capacity * 2 + 1;
    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity));
     // TODO: maybe switch them?       ^~~~~~~~ you've done it twice

    if(stk->data == NULL)
    {
        return NOT_ENOUGH_MEMORY; // TODO: add logging strerror
    }
    else
    {
        return SUCCESS;
    }
}

int stack_pop(struct Stack* stk) // TODO: you could use out parameter, see quadratic equation solver.
{
    if(stk->size < 1)
    {
        printf("The stack is empty\n");
        return EMPTY_STACK_ERROR;
    }  

    int val = stk->data[stk->size - 1];
    stk->size--; // TODO: pick one!
    printf("You pulled an element from the stack, the value is equal to %d\nNew size is: %d\n", val, stk->size);
    return val; // TODO: you're returning error code as well as number
}

void stack_print(struct Stack* stk) // TODO: do not expose internals!
{
    printf("\n\nThe stack now looks like this:\n");
    for(int i = 0; i < stk->capacity; i++)
    {
        printf("|%d", stk->data[i]);
    }
    printf("|\n\n");
}