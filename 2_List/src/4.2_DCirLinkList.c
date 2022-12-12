#include "4.2_DCirLinkList.h"
#include <stdlib.h>

void printList(DouLinkList pL)
{
    if (!pL)
        return ERROR;
    DouLNode *pMove = pL;
    while(pMove->next != pL)
    {
        printf("%d ", pMove->next->data);
        pMove = pMove->next;
    }
    printf("\n");
}


//（1）初始化
Status initList(DouLinkList *ppL)
{
    *ppL = (DouLinkList)malloc(sizeof(DouLinkList));
    if (!ppL)
        exit(OVERFLOW);
    
    // 前驱和后继都指向自身
    (*ppL)->next = (*ppL)->prior = *ppL;
}

//（2）插入
Status listInsert(DouLinkList pL, int i, ElemType e)
{
    if (!pL)
    {
        printf("[WARNING]: LIST NOT EXIST!\n");
        return ERROR;
    }

    DouLNode *pMove = pL;
    int count = -1;

    // 遍历到第 i 个结点
    while(pMove->next != pL && count < i)
    {
        pMove = pMove->next;
        count++;
    }
    
    // 判断越界
    // 此时 pMove 为第 i 个结点
    // 或者如果 i 超过头结点，责问为头结点的前一结点，此时 count = 表的元素数
    // i < 0 || i 超过了头结点的位置
    if (i < 0 || count + 1 < i)
    {
        printf("[WARNING]: INVALID INDEX!\n");
        return ERROR;
    }
    
    DouLNode *pNewNode = (DouLNode*)malloc(sizeof(DouLNode));
    if (!pNewNode)
        exit(OVERFLOW);
    
    pNewNode->data = e;

    // 将 pNewNode 插入到 pMove 的位置，称为第 i 个结点
    pNewNode->next     = pMove;
    pNewNode->prior    = pMove->prior;
    pMove->prior->next = pNewNode;
    pMove->prior       = pNewNode;

    return OK;
}

//（3）删除
Status listDelete(DouLinkList pL, int i, ElemType *pE)
{
    // 确保链表存在并且不为空
    if (!pL || pL->next == pL || pL->prior == pL)
    {
        printf("[WARNING]: LIST NOT EXIST OR EMPTY LIST!");
        return ERROR;
    }
    
    // 
    DouLNode *pMove = pL;
    int count = -1;
    // 遍历到第 i 个点
    while(pMove->next != pL && count < i)
    {
        printf("while loop\n");
        pMove = pMove->next;
        count++;
    }
    printf("count = %d\n", count);
    // 判断越界
    if (i < 0 || count+1 < i)
    {
        printf("[WARNING]: INVALID INDEX!");
        return ERROR;
    }

    *pE = pMove->data;

    // 移除 pMove 结点
    pMove->prior->next = pMove->next;
    pMove->next->prior = pMove->prior;

    free(pMove);
    return OK;
}

//（4）查找
int locateElem(DouLinkList pL, ElemType e)
{
    // 确保链表存在并且不为空
    if (!pL || pL->next == pL || pL->prior == pL)
    {
        printf("[WARNING]: LIST NOT EXIST OR EMPTY LIST!");
        return ERROR;
    }

    DouLNode *pMove = pL;
    int count = -1;
    // 
    while (pMove->next != pL && pMove->data != e)
    {
        pMove = pMove->next;
        count++;
    }

    if (pMove != pL)
        return count;
    else    
        return 0;
}

//（5）取值
Status getElem(DouLinkList pL, int i, ElemType *pE)
{
    if (!pL || pL->next == pL || pL->prior == pL)
    {
        printf("[WARNING]: LIST NOT EXIST OR EMPTY LIST!\n");
        return ERROR;
    }

    DouLNode *pMove = pL;
    int count = -1;
    while(pMove->next != pL && count < i)
    {
        pMove = pMove->next;
        count++;
    }

    if (i < 0 || count+1 < i)
    {
        printf("[WARNING]: INVALID INDEX!\n");
        return ERROR;
    }
    *pE = pMove->data;
    return OK;
}