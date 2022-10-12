
#include <stdio.h>
#include <stdlib.h>

struct Info // TODO: This is more of a source_location than generic "info" (Even better, comment for now)
{
    const char* name; // TODO: Who is name
    const char* func;
    const char* file;
    int line;
};

struct Stack
{
    int* data; //the pointer to the top of the stack
    int size;
    int capacity;
    struct Info info; // TODO: ? Rename! (Even better, delete for now)
};

// TODO: order of development should be:
//       1. write working simple stack without any protection
//       2. add canaries
//       3. add hashing

// Beware: don't add everything at the same time! It's dangerous!

// TODO: weird naming, examples of the opposite.
//
// Hello world => hello_world
//             => HelloWorld
//
// helloWorld -- function, HelloWorld -- struct
// hello_world -- function, HelloWorld -- struct

enum Error_Sensitive_Exit_Codes // TODO: Pascal_Case_With_Underscores, why?
{ // TODO: what are these errors for? StackErrorCode
    SUCCESS        = 0,
    RESIZE         = 1, // TODO: Why?
};

// TODO: idea of error codes is:

// your_enum_name status = StackPop(&stk, &x);
// if (status == SUCCESS || status == RESIZE || status == DOWNSIZE) ...

int main ()
{
    Stack stk = {};

    // TODO: definitely not a pointer here: Stack* ptr; // -- wrong
    // TODO: equivalent (*ptr).data; with ptr->data;

    // pointer to stk (ptr_stk)
    // |
    // v
    // [ ] [ ] [ ] [ ] [ ]
    // [x] [y    ] [z    ]
    // int  float   size_t
    // [stk              ]
    // your_struct (with fields int, float, size_t)

    // stk.x, stk.y, stk.z
    // (*ptr_stk).x; // field access through pointer

    //   ptr_stk->x; // same thing, but shorter and nicer



    // TODO: If you want, you can add peek
    stack_ctor(&stk, 5);

    stack_push(&stk, 1);
    stack_push(&stk, 4);
    stack_push(&stk, 3);

    stack_pop(&stk, &3);
    stack_push(&stk, 2);

    stack_print(stk);

    stack_pop(&stk, &2);
    stack_pop(&stk, &4);
    stack_pop(&stk, &1);

    stack_dtor(&stk);

    return SUCCESS;
}

void stack_ctor (struct Stack* stk, int stk.capacity)
{ // TODO:                              ^~~~ does not compile
  //       You need to first accept argument and than write it in field,
  //       there's no way to do it right away.

  //       But named designators might help you. stk = { .data = ..., ... };

    int* data = (int*) calloc(stk.capacity, sizeof(int));
    // TODO:                     ^ stk is a pointer, does not compile!
    //                             use arrow instead (because stk is a pointer)

    // Dot (.) can never be used with a pointer!
}

void stack_dtor(struct Stack* stk)
{
    free(Stack.data);
    //        ^ same thing, consider zeroing pointer to data,
    //          it is useful because it will allow you to call dtor again
    //          without double free

    // TODO: also it's useful to have some kind of marker in
    //       stack that can tell that it has already been
    //       destructed. (for example negative value for something strictly positive),
    //       zero capactiy or whatever you like.
}

void stack_push(struct  Stack* stk, int value)
{ 
    // TODO: do not use spaces around arrow!
    // stk -> size < stk -> capacity
    //     ^~      ^     ^~ makes it look confusing, it's not clear what is most important, but it should be

    // stk->size < stk->capacity // Now it's clear that "<" is the most important thing, we're comparing two numbers

    if(stk -> data == NULL) // TODO: do not call constructor instead of user
                            //       but you can add assert (or something more eleborate, but later)
    {
        stack_ctor(*stk, stk.capacity);
        // TODO:            ^
    }

    else
    {  
        if(find_empty_cell(stk) == RESIZE)
        { // TODO: Why? stk->data[size] should always be free
          // TODO: Should check here if enough space instead (capacity is big enough)
            stack_resize();
        }
        data[stk.size] = value;
    // TODO:    ^
    }
}

void stack_pop(struct Stack* stk, int value) // stack_pop may return value that was on top
{ // TODO:                        ^~~~~~~~~ because it does not belong here!
    
}

void stack_resize() // TODO: :)
{

}

int find_empty_cell(struct Stack* stk) // TODO: you always know which cell is empty
{                                      //       it's the whole idea of stack
    for(int i = 0; i < stk.capacity; i++)
    { // TODO:            ^
        if(stk -> data + i == 0)
        {
            stk.size == i;
        }
    }

    if(stack_is_full)
    {
        return RESIZE;
    }

    return stk.size;
    // TODO:  ^
}

bool stack_is_full(struct  Stack* stk) // TODO: shouldn't be this complex
{
    for(int i = 0; i < stk.capacity; i++) // TODO: no need for loops to determine is stack full or not
    {
        if(stk -> data + i != 0)
        {
            return true;
        }
    }
return false; // TODO: alignment?
}

