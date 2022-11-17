//=============================================================================
#include <stdlib.h>

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

int get_random(int from, int to);
static int CANARY_BUF = get_random (10, RAND_MAX);
static int CANARY_STRUCT = get_random (10, RAND_MAX);
const int NUMBER_OF_CANARIES = 2;

void add_buffer_canaries(struct Stack* stk);
int check_buffer_canaries(struct Stack* stk);
int check_struct_canaries(struct Stack* stk);
void add_struct_canaries(struct Stack* stk);
void check_canaries(struct Stack* stk);
void add_protection(struct Stack* stk);
int* stack_get_base_ptr(struct Stack* stk);
