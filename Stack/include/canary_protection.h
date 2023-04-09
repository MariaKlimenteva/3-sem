//=============================================================================
#ifndef CANARY_PROTECTION_H
#define CANARY_PROTECTION_H

#include <stdlib.h>

// 0b000001
// 0b000010
// 0b000100

// return LEFT_CANARY_INVALID | RIGH_CANARY_INVALID; // returns error code that contains information about both

// 0b000001
// 0b000010
// --------
// 0b000011

// int error = ...
// if (error & LEFT_CANARY_INVALID)
//     ...

// 0b000011
// 0b000001
// --------
// 0b000001

int get_random(int from, int to);

extern int CANARY_BUFFER;
extern int CANARY_STRUCT;

const int NUMBER_OF_CANARIES = 2;

static void add_buffer_canaries(struct Stack* stk);
static int check_buffer_canaries(struct Stack* stk);
static int check_struct_canaries(struct Stack* stk);
static void add_struct_canaries(struct Stack* stk);
static void check_canaries(struct Stack* stk);
static void add_protection(struct Stack* stk);
static int* stack_get_base_ptr(struct Stack* stk);

// TODO: why canary_protection.h and stack.h are separated?
// (make this functions static inside stack.cpp or think about better design)

// Every header should be self contained and have integrity (e.g. to use stack
// i need this, and that, therefore it's good idea to place them, or, at least,
// include in stack.h)

#endif // CANARY_PROTECTION_H
