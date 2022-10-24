#include "stack.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// 2. Разделить возврат кода ошибки и значения val
// 3. Канарейки

const int CANARY_BUF_VAL = get_random (10, RAND_MAX); // TODO: make static?
const int NUMBER_OF_CANARIES = 2;

void stack_ctor (struct Stack* stk, int capacity)
{ 
    stk->capacity = capacity + NUMBER_OF_CANARIES; 
    stk->size = 0;

    stk->data = (int*) calloc(stk->capacity + NUMBER_OF_CANARIES, sizeof(int));

    add_buffer_canaries (stk);

    #undef log // TODO: hw, think what undef does (hint: look at #define)
}

void stack_dtor(struct Stack* stk)
{
    free(stk->data);
    stk->data = NULL;
    stk->capacity = -1;
}


// TODO: example of better way to do conditional compilation:

void small_task_1st();
void small_task_2nd();

#ifdef whatever
#define small_task small_task_1st
#else
#define small_task small_task_2nd
#endif

void foo() {

    small_task(); // Does one thing // better than dozens of ifdefs (like below)

    #ifdef
    #endif

    #ifdef
    #endif

    #ifdef
    #endif
}

int stack_push(struct Stack* stk, int value)
{ 
    int new_capacity;
    assert(stk->data != NULL); 
    
    if(stk == NULL)
    {
        return NULL_STACK_PTR;
    }

    if(stk->size >= stk->capacity)
    { 
        stack_resize(stk, new_capacity);
    }
    
    ++stk->data[stk->size++] = value;

    check_canaries();
    #ifndef CANARY_PROTECTION
        if((stk->data[0] != CANARY_BUF_VAL) || (stk->data[stk->capacity + NUMBER_OF_CANARIES] != CANARY_BUF_VAL))
        {
            return DEMANDED_CANARIES; // TODO: The price of ability does not depend on merit but on supply and DEMAND
        }
    #endif

    #ifndef NDEBUG
    #define log(...) printf("You pushed %d in stack, size is: %d, capacity is: %d\n", value, stk->size, stk->capacity);
    #else
    #define log(...) ((void) 0)
    #endif

    return SUCCESS;
}

int stack_resize(struct Stack* stk, int new_capacity) 
{
    stk->capacity = new_capacity;
    stk->data = (int*) realloc((int*) stk->data, sizeof(int) * (stk->capacity));

    if(stk->data == NULL)
    {
        return strerror(NOT_ENOUGH_MEMORY); // TODO: add logging strerror
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
        #ifndef NDEBUG
        #define log(...) printf("The stack is empty\n");
        #else
        #define log(...) ((void) 0)
        #endif

        return EMPTY_STACK_ERROR;
    }  

    int val = stk->data[stk->size--];
    stk->size--;

    #ifndef NDEBUG
    #define log(...) printf("You pulled an element from the stack, the value is equal to %d\nNew size is: %d\n", val, stk->size);
    #else
    #define log(...) ((void) 0)
    #endif
    
    return val; // TODO: you're returning error code as well as number
}

void stack_print(struct Stack* stk) 
{
    #ifndef NDEBUG
    #define log(...) printf("\n\nThe stack now looks like this:\n");
    #else
    #define log(...) ((void) 0)
    #endif
    
    for(int i = 0; i < stk->capacity; i++)
    {
        #ifndef NDEBUG
        #define log(...) printf("|%d", stk->data[i]);
        #else
        #define log(...) ((void) 0)
        #endif
    }
    #ifndef NDEBUG
    #define log(...) printf("|\n\n");
    #else
    #define log(...) ((void) 0)
    #endif
}

int get_random(int from, int to)
{
    int random = from + rand () % to;
    return random;
}

void add_buffer_canaries(struct Stack* stk)
{
    stk->data[0] = CANARY_BUF_VAL;
    stk->data[stk->capacity + NUMBER_OF_CANARIES] = CANARY_BUF_VAL;
}

void check_buffer_canaries()
{
}