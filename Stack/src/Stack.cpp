#include "stack.h"
#include "stack_log.h"
#include "canary_protection.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>

void stack_ctor (struct Stack* stk, int capacity)
{ 
    stk->capacity = capacity; 
    stk->size = 0;

    stk->data = (int*) calloc(stk->capacity + NUMBER_OF_CANARIES, sizeof(int));

    add_protection(stk);
    check_canaries(stk);
    log("Stack was create, capacity is: %d, size is: %d\n", stk->capacity, stk->size);
}

void stack_dtor(struct Stack* stk)
{
    free(stk->data);
    stk->data = NULL;
    stk->capacity = -1;
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
        stack_resize(stk, new_capacity);
    }

    stack_get_base_ptr(stk)[stk->size] = value;
    // stk->data[stk->size + NUMBER_OF_CANARIES - 1] = value;
    // (...) stk->data + ... + sizeof(CANARY_TYPE)
    stk->size++;

    check_canaries(stk);

    log("You pushed %d in stack, size is: %d, capacity is: %d\n", value, stk->size, stk->capacity);

    return SUCCESS;
}

int stack_resize(struct Stack* stk, int new_capacity) 
{
    check_canaries(stk);

    stk->capacity = new_capacity;

    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity + NUMBER_OF_CANARIES));//stk->data
    // TODO: Why don't you fill rest of stack's capacity with poison?

    if(stk->data == NULL)
    {
        return NOT_ENOUGH_MEMORY;
    }
    else
    {
        stack_get_base_ptr(stk)[stk->capacity] = CANARY_BUF;
        // stk->data[stk->capacity + NUMBER_OF_CANARIES - 1] = CANARY_BUF;
        return SUCCESS;
    }
}

int stack_pop(struct Stack* stk, int* return_val)
{
    check_canaries(stk); // TODO: more general check?

    if(stk->size < 1)
    {
        log("The stack is empty\n");
        return EMPTY_STACK_ERROR;
    }

    // stack_get_buffer_ptr(stk)

    *return_val = stk->data[stk->size];
    stk->size--;


    log("You pulled an element from the stack, the value is equal to %d\nNew size is: %d\n", *return_val, stk->size);

    return SUCCESS;
}

void stack_print(struct Stack* stk) 
{
    log("\n\nThe stack now looks like this:\n");
    
    for(int i = 0; i < stk->capacity + NUMBER_OF_CANARIES; i++)
    {
        log("|%d", stk->data[i]);
    }
    
    log("|\n\n");
}