#define DEF_CMD(name, num, arg, codd)\
    case num:

    codd
    ip += 1
    break;


void Run()
{
    while()
    {
        switch(codes_arr[ip] ...)
        {
            case CMD_ADD:
            Push(&stk, Pop(&stk) + Pop(&stk));
            ip += 1;
            break;

            case CMD_SUB:
            Push(&stk, Pop(&stk) - Pop(&stk));
            ip += 1;
            break;

            case CMD_MUL:
            Push(&stk, Pop(&stk) * Pop(&stk));
            ip += 1;
            break;

            case CMD_PUSH:
            Push(&stk, get_arg(codes_arr, &ip));
            ip += 1;
            break;
        }
    }
}