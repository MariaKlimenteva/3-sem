//=============================================================================
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

struct Stack
{
    int* data; //the pointer to the top of the stack
    int size; //the number of elements that actually exist
    int capacity; 
};

// TODO: order of development should be:
//       1. write working simple stack without any protection
//       2. add canaries
//       3. add hashing

// Beware: don't add everything at the same time! It's dangerous!

enum StackErrorCode 
{
    SUCCESS = 0,
    NOT_ENOUGH_MEMORY = 1,
    EMPTY_STACK_ERROR = 2,
};
const int RESIZE = 1;

//-----------------------------------------------------------------------------
//! @brief allocate memory for the stack.
//!
//! @param [in] stk - the structure that implements the software stack.
//!
//! @param [in] capacity - the amount of allocated memory
//-----------------------------------------------------------------------------
void stack_ctor (struct Stack* stk, int capacity);

//-----------------------------------------------------------------------------
//! @brief free up the memory allocated for the stack.
//!
//! @param [in] stk - the structure that implements the software stack.
//-----------------------------------------------------------------------------
void stack_dtor(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief put an element on the stack.
//!
//! @param [in] stk - the structure that implements the software stack.
//!
//! @param [in] value - the value of the element that we put on the stack. 
//-----------------------------------------------------------------------------
void stack_push(struct  Stack* stk, int value);

//-----------------------------------------------------------------------------
//! @brief change the amount of memory allocated to the stack.
//!
//! @param [in] stk - the structure that implements the software stack.
//!
//! @return error NOT_ENOUGH_MEMORY or success code.
//-----------------------------------------------------------------------------
int stack_resize(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief pull the top element from the stack.
//!
//! @param [in] stk - the structure that implements the software stack.
//!
//! @return the value of the item that was taken out or the error code EMPTY_STACK_ERROR if the stack is empty.
//-----------------------------------------------------------------------------
int stack_pop(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief make a stack printout, in the form of an array
//!
//! @param [in] stk - the structure that implements the software stack.
//-----------------------------------------------------------------------------
void stack_print(struct Stack* stk);

#endif // STACK_H
