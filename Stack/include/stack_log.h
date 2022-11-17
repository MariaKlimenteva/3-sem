//=============================================================================
#ifndef STACK_LOG_H
#define STACK_LOG_H

#include <stdio.h>

#ifndef NDEBUG // you can define it with -DNDEBUG 
#define log(...) printf(__VA_ARGS__)
#else
#define log(...) ((void) 0)
#endif

#ifndef NCANARY_PROT 
#define add_buffer_canaries(stk)  add_buffer_canaries(stk)
#define add_struct_canaries(stk)  add_struct_canaries(stk)
#define check_buffer_canaries(stk)  check_buffer_canaries(stk)
#define check_struct_canaries(stk) check_struct_canaries(stk)
#else 
#define add_buffer_canaries(stk) ((void) 0)
#define add_struct_canaries(stk) ((void) 0)
#define check_buffer_canaries(stk) ((void) 0)
#define check_struct_canaries(stk) ((void) 0)
#endif


#endif // STACK_LOG_H