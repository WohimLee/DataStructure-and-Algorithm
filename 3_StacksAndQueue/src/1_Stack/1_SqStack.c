
#include "1_SqStack.h"
#include <stdlib.h>
#include <stdio.h>

void printStack(SqStack S)
{
    if (!S.base || S.top==S.base)
    {
        printf("[WARNING]: LIST NOT EXIST! OR LIST EMPTY!\n");
        exit(ERROR);
    }
    SElemType* pMove = S.base;
    while (pMove < S.top)
    {
        printf("%d ", *pMove);
        pMove++;
    }
    printf("\n");
}


//（1）初始化
Status initStack(SqStack *pS)
{
    if (!pS)
        return ERROR;

    pS->base = (SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
    if (pS->base == NULL)
        exit(OVERFLOW);
    pS->top  = pS->base;
    pS->size = STACK_INIT_SIZE;

    return OK;
}

//（2）销毁（结构）
Status destroyStack(SqStack *pS)
{
    if (!pS)
        return ERROR;
    
    free(pS->base);

    pS->base = NULL;
    pS->top  = NULL;
    pS->size = 0;

    return OK;
}

//（3）置空（内容）
Status clearStack(SqStack *pS)
{
    if (!pS || !pS->base)
        return ERROR;
    pS->top = pS->base;

    return OK;
}

//（4）判空
Status stackEmpty(SqStack S)
{
    return S.top == S.base? TRUE : FALSE;
}

//（5）计数
int stackLength(SqStack S)
{
    if (!S.base)
        return 0;
    return (int)(S.top - S.base);
}

//（6）入栈
Status push(SqStack *pS, SElemType e)
{
    if (!pS || !pS->base)
        return ERROR;
    // 栈满时，追加存储空间
    if (pS->top - pS->base >= pS->size)
    {
        pS->base = (SElemType*) realloc(pS->base, sizeof(SElemType)*(pS->size+STACKINCREMENT));
        if (!pS->base)
            exit(OVERFLOW);
        pS->top   = pS->base + pS->size;
        pS->size += STACKINCREMENT;
    }

    // 进栈先赋值，栈顶指针再自增
    *(pS->top++) = e;
    return OK;
}

//（7）出栈
Status pop(SqStack *pS, SElemType *pE)
{
    if (!pS || !pS->base)
        return ERROR;
    
    if (pS->top == pS->base)
        return ERROR;
    // 出栈栈顶元素先递减，再赋值
    *pE = *(--pS->top);

    return OK;
}

//（8）取栈顶元素
SElemType getTop(SqStack S)
{
    if (!S.base || S.top == S.base)
        return ERROR;
    
    // 不会改变栈中的元素
    return *(S.top - 1);
}
