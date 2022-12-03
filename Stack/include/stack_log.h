//=============================================================================
#ifndef STACK_LOG_H
#define STACK_LOG_H


#ifndef NCANARY_PROT

#define add_protection_(stk) add_protection(stk) 
#define check_canaries_(stk) check_canaries(stk)

#else 
#define add_protection_(stk) ((void) 0)
#define check_canaries_(stk) ((void) 0)

#endif


#endif // STACK_LOG_H