#include "canary_protection.h"
#include "stack.h"
#include "log.h"

int CANARY_BUFFER = get_random(10, RAND_MAX);
int CANARY_STRUCT = get_random(10, RAND_MAX);

int get_random(int from, int to)
{
    int random = from + rand () % to;
    return random;
}

int* stack_get_base_ptr(struct Stack* stk)
{
    #ifndef NCANARY_PROT
    return stk->data + 1; // TODO: Should change when canaries are disabled!
    #else
    return stk->data;
    #endif
}

void add_buffer_canaries(struct Stack* stk)
{
    stk->data[0] = CANARY_BUFFER;
    stack_get_base_ptr(stk)[stk->capacity] = CANARY_BUFFER;
}

int check_buffer_canaries(struct Stack* stk)
{
    if(stk->data[0] != CANARY_BUFFER)
    {
        log("Your left buffer canary is damaged\n");
        return LEFT_BUFFER_CANARY_INVALID;
    }

    if(stk->data[stk->capacity + 1] != CANARY_BUFFER)
    {
        log("Your right buffer canary is damaged\n");
        return RIGHT_BUFFER_CANARY_INVALID;
    }
    return SUCCESS;
}

void add_struct_canaries(struct Stack* stk)
{
    stk->left_canary  = CANARY_STRUCT;
    stk->right_canary = CANARY_STRUCT;
}

int check_struct_canaries(struct Stack* stk)
{
    if(stk->left_canary != CANARY_STRUCT)
    {
        log("The left canary in your struct is not valid\n");
        return LEFT_STRUCT_CANARY_INVALID;
    }
    if(stk->right_canary != CANARY_STRUCT)
    {
        log("The right canary in your struct is not valid\n");
        return RIGHT_STRUCT_CANARY_INVALID;
    }
    return SUCCESS;
}

void check_canaries(struct Stack* stk)
{
    check_buffer_canaries(stk);
    check_struct_canaries(stk);
}

void add_protection(struct Stack* stk)
{
    add_buffer_canaries(stk);
    add_struct_canaries(stk);
}