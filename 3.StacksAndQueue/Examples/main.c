#include <stdio.h>
// #include "1_SqStack.h"
#include "6.3_Expression.h"


Status Matching()
{
    SqStack S;
    SElemType e;
    initStack(&S);
    int flag = 1;
    char ch;
    scanf("%c", &ch);
    while (ch != '#' && flag)
    {
        switch (ch)
        {
            case '[' || '(':
                push(&S, ch);
                printf("Push '%c' in stack.\n", ch);
                break;
            case ')':
                getTop(S, &e);
                if (!stackEmpty(S) && e == '(')
                {
                    pop(&S, e);
                    printf("Pop '%d' in stack.\n", &e);
                }
                else flag = 0;
                break;
            case ']':
                getTop(S, &e);
                if (!stackEmpty(S) && e == '[')
                {
                    pop(&S, e);
                    printf("Pop '%d' in stack.\n", &e);
                }
                else flag = 0;
                break;
            default :
                printf("[WARNING]: ERROR!\n");
        }
        scanf("%c", &ch);
    }
    if (stackEmpty(S) && flag) 
        return TRUE;
    else    
        return FALSE;
}

void printResult(int res)
{
    if (res == 1)
        printf("Match!\n");
    else if (res == 0)
        printf("Not Match!\n");
}





int main()
{
    char opnd;
    char* exp = "(1+3)*2/4#";
    
    opnd = EvaluateExpression(exp);

    printf("作为示例， %s 的计算结果为：%d\n", exp, opnd - '0');

    return 0;
    return 0;
}