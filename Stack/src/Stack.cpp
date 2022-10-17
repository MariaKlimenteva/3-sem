#include "stack.h"

void stack_ctor (struct Stack* stk, int capacity)
{ 
    stk->capacity = capacity; 

    stk->data = (int*) calloc(stk->capacity, sizeof(int));

    printf("Stack was create, capacity is: %d, size is: %d\n", stk->capacity, stk->size);
}

void stack_dtor(struct Stack* stk)
{
    assert(stk->data != NULL);

    free(stk->data);
    //        ^ same thing, consider zeroing pointer to data,
    //          it is useful because it will allow you to call dtor again
    //          without double free

    stk->capacity = -1; //shows, that the stack has already destructed
}

void stack_push(struct  Stack* stk, int value)
{ 
    assert(stk->data != NULL);
    
    if(stk->size >= stk->capacity)
        {
            stack_resize(stk);
        }
    
    stk->data[stk->size++] = value;
    printf("You pushed %d in stack, size is: %d, capacity is: %d\n", value, stk->size, stk->capacity);
}

int stack_resize(struct Stack* stk) 
{
    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity * 2 + 1)); 
    if(stk->data == NULL)
    {
        return NOT_ENOUGH_MEMORY;
    }
    else
    {
        return SUCCESS;
    }
}

int stack_pop(struct Stack* stk) 
{
    if(stk->size < 1)
    {
        printf("The stack is empty\n");
        return EMPTY_STACK_ERROR;
    }  

    int val = stk->data[stk->size - 1];
    stk->size--;
    printf("You pulled an element from the stack, the value is equal to %d\nNew size is: %d\n", val, stk->size);
    return val;  
    
}

void stack_print(struct Stack* stk)
{
    printf("\n\nThe stack now looks like this:\n");
    for(int i = 0; i < stk->capacity; i++)
    {
        printf("|%d", stk->data[i]);
    }
    printf("|\n\n");
}