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
    int capacity; //the amount of allocated memory
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
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
void stack_ctor (struct Stack* stk, int capacity);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
void stack_dtor(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
void stack_push(struct  Stack* stk, int value);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int stack_resize(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
int stack_pop(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief
//!
//! @param [in]
//!
//! @return 
//-----------------------------------------------------------------------------
void stack_print(struct Stack* stk);

#endif // STACK_H
