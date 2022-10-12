#ifndef COMMANDS_H
#define COMMANDS_H

#define COMMA ,

DEF_CMD(PUSH, 1, 1,
{
    Push(&stk, arg);
})

DEF_CMD(ADD, 2, 0,
{
    Push(&stk, Pop(&stk) + Pop(&stk));
})

DEF_CMD(SUB, 3, 0,
{
    int a = Pop(&stk) COMMA b = Pop(&stk);
    Push(a - b);
})

DEF_CMD(MUL, 4, 0,
{
    Push(&stk, Pop(&stk) * Pop(&stk));
})

DEF_CMD(DIV, 5, 0,
{
    int a = Pop(&stk) COMMA b = Pop(&stk);
    if(b)
    {
        Push(a/b);
    }
    else
    {
        printf("Error")
    }
})
    
DEF_CMD(OUT, 6, 1,
{
    Pop(&stk, arg);
})

DEF_CMD(HLT, 7, 0,
{

})

#endif // COMMANDS_H