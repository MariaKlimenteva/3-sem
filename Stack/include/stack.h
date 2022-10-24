//=============================================================================
#ifndef STACK_H
#define STACK_H

struct Stack
{
    
    int* data; //the pointer to the top of the stack
    int size; //the number of elements that actually exist
    int capacity; 

};

// TODO: order of development should be:
//       2. add canaries
//       3. add hashing

// Beware: don't add everything at the same time! It's dangerous!

enum StackErrorCode 
{
    SUCCESS = 0,
    NOT_ENOUGH_MEMORY = 1,
    EMPTY_STACK_ERROR = 2,
    NULL_STACK_PTR = 3,
    DEMANDED_CANARIES = 4,
};

//-----------------------------------------------------------------------------
//! @brief construct memory for the stack.
//!
//! @param [in] stk - protected stack.
//                    
//!
//! @param [in] capacity - initial buffer size
//-----------------------------------------------------------------------------
void stack_ctor (struct Stack* stk, int capacity);

//-----------------------------------------------------------------------------
//! @brief destruct the stack. stk->capacity = -1 - shows, that the stack has already destructed
//!
//! @param [in] stk - protected stack.
//-----------------------------------------------------------------------------
void stack_dtor(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief put an element on the stack.
//!
//! @param [in] stk - protected stack.
//!
//! @param [in] value - the value of the element that we put on the stack. 
//-----------------------------------------------------------------------------
int stack_push(struct  Stack* stk, int value);

//-----------------------------------------------------------------------------
//! @brief change the amount of memory allocated to the stack.
//!
//! @param [in] stk - protected stack.
//!
//! @return error NOT_ENOUGH_MEMORY or success code.
//-----------------------------------------------------------------------------
int stack_resize(struct Stack* stk, int new_capacity);

//-----------------------------------------------------------------------------
//! @brief delete the top element from the stack.
//!        
//! @param [in] stk - protected stack.
//!
//! @return the value of the item that was taken out or the error code EMPTY_STACK_ERROR if the stack is empty.
//-----------------------------------------------------------------------------
int stack_pop(struct Stack* stk);

//-----------------------------------------------------------------------------
//! @brief make a stack printout, in the form of an array
//!
//! @param [in] stk - protected stack.
//-----------------------------------------------------------------------------
void stack_print(struct Stack* stk);

int get_random(int from, int to);
void add_buffer_canaries(struct Stack* stk);

#endif // STACK_H
