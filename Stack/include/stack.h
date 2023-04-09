//=============================================================================
#ifndef STACK_H
#define STACK_H

struct Stack
{
    #ifndef NCANARY_PROT
    int left_canary;
    int* data; //the pointer to the top of the stack
    int size; //the number of elements that actually exist
    int capacity; 
    int right_canary; // TODO: ability to switch off canaries
    #else
    int* data; //the pointer to the top of the stack
    int size; //the number of elements that actually exist
    int capacity; 
    #endif
};

enum StackErrorCode 
{
    SUCCESS = 0,
    NOT_ENOUGH_MEMORY = 1,
    EMPTY_STACK_ERROR = 2,
    NULL_STACK_PTR = 3,
    LEFT_BUFFER_CANARY_INVALID = 4,
    RIGHT_BUFFER_CANARY_INVALID = 5,
    LEFT_STRUCT_CANARY_INVALID = 6,
    RIGHT_STRUCT_CANARY_INVALID = 7,
};

//-----------------------------------------------------------------------------
//! @brief construct memory for the stack.
//!
//! @param [in] stk - protected stack.       
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
[[nodiscard]]
int stack_push(struct  Stack* stk, int value);
//^ TODO: why not use enum?)

//-----------------------------------------------------------------------------
//! @brief change the amount of memory allocated to the stack.
//!
//! @param [in] stk - protected stack.
//!
//! @return error NOT_ENOUGH_MEMORY or success code.
//-----------------------------------------------------------------------------
[[nodiscard]]
int stack_resize(struct Stack* stk, int new_capacity);

//-----------------------------------------------------------------------------
//! @brief delete the top element from the stack.
//!        
//! @param [in] stk - protected stack.
//!
//! @param [out] return_val - the value of element that was delete from the stack.
//! 
//! @return the value of the item that was taken out or the error code EMPTY_STACK_ERROR if the stack is empty.
//-----------------------------------------------------------------------------
[[nodiscard]]
int stack_pop(struct Stack* stk, int* return_val);

//-----------------------------------------------------------------------------
//! @brief make a stack printout, in the form of an array
//!
//! @param [in] stk - protected stack.
//-----------------------------------------------------------------------------
void stack_print(struct Stack* stk);
void memory_allocation(struct Stack* stk);

#endif // STACK_H
