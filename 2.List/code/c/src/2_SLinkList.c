#include "2_SLinkList.h"
#include <stdlib.h>
#include <stdio.h>

// void printList(LinkList pL)
// {
//     LNode* temp = pL->next;
//     for (int i = 0; i < pL->data; i++)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

void printList(LinkList pL)
{
    while (pL->next)
    {
        printf("%d ", (pL->next)->data);
        pL = pL->next;
    }
    printf("\n");
}


// （1）初始化
Status initList(LinkList *ppHeadNode)
{
    *ppHeadNode = (LNode*)malloc(sizeof(LNode));
    if (!ppHeadNode) // 也可以写 L == NULL
        exit(OVERFLOW);
    (*ppHeadNode)->next = NULL;
}

// （2）取值
Status getElem(LinkList pL, int i, ElemType *pE)
{   
    // 确保链表存在且后继不为空
    if (!pL || !pL->next)
        return ERROR;
    
    LNode *pMove = pL; // pMove 赋初始值为头结点
    int count = -1;    // 计数器，-1 为头结点
    // 遍历到第 i-1 个点，且该点有后继 next 结点（即第 i 个元素）

    while(pMove->next && count < i-1)
    {
        pMove = pMove->next;
        count++;
    }
    // 此时 pMove 是第 i-1 个点
    // 如果 pMove 没有后继 next 结点（i 大于表长） || i 小于 0
    if (!pMove->next || count > i-1)
    {
        printf("[WARNING]: OUT OF RANGE!");
        return ERROR;
    }
    // 此时 pMove 是第 i-1 个点，取其 next 的数据域 data
    *pE = (pMove->next)->data;
    return OK;
}

// （3）查找
LNode *locateElem(LinkList pL, ElemType e)
{
    // 确保链表存在且不为空表
    if (!pL || !pL->next)
        return 0;
    
    int i = 0;               // 
    LNode *pMove = pL->next; // 
    while (pMove && pMove->data != e)
    {
        pMove = pMove->next;
        i++;
    }
    if (pMove != NULL)
        return i;
    else
    {
        printf("[WARNING]: NONE!");
        return -1;
    }
}

// （4）插入（默认已存在链表，且元素个数大于1）
Status listInsert(LinkList pL, int i, ElemType e)
{
    if (!pL)
        return ERROR;
    
    LNode *pMove = (LNode*)malloc(sizeof(LNode));
    pMove = pL;     // 给 pMove 赋初值为头结点
    int count = -1; // -1 是头结点
    // 遍历到第 i-1 个结点
    while (pMove && count < i-1)
    {
        pMove = pMove->next;
        count++;
    }

    // 此时 pMove 是第 i-1 个结点
    // 如果 pMove 不存在 || i 的位置 < 0
    if (!pMove || count > i-1)
    {
        printf("[WARNING]: INVALID INDEX!\n");
        return ERROR;
    }
   
    // 生成新结点
    LNode *pNewNode = (LNode*)malloc(sizeof(LNode));
    if (!pNewNode)
        exit(OVERFLOW);

    pNewNode->data = e;
    pNewNode->next = pMove->next;
    pMove->next = pNewNode;
    
    return OK;
}

// （5）删除
Status listDelete(LinkList pL, int i, ElemType *pE)
{
    // 确保链表存在，且不为空表
    if (!pL || !pL->next)
        return ERROR;
    
    LNode *pMove = pL;
    int count = -1;

    // 遍历到第 i-1 个结点，且该结点有后继结点（即第 i 个结点） 
    // && i >= 0
    while (pMove->next && count < i-1)
    {
        pMove = pMove->next;
        count++;
    }

    // 此时 pMove 为第 i-1 个结点
    // 如果第 i-1 个结点 的 next 为NULL || i < 0
    // 说明 i 值不合法
    if (!pMove->next || count > i-1)
    {
        printf("[WARNING]: INVALID INDEX!");
        return ERROR;
    }
    
    // 删除第 i 个结点
    LNode *pTemp;
    pTemp = pMove->next;
    pMove->next = pTemp->next;
    *pE = pTemp->data;

    free(pTemp);
    return OK;
}

// （6）创建单链表（前插）
Status createList_Head(LinkList *ppHeadNode, int n)
{
    LNode *pNewNode;
    // 建立头结点
    *ppHeadNode = (LinkList)malloc(sizeof(LNode));
    (*ppHeadNode)->next = NULL;

    for (int i = 0; i < n; ++i)
    {
        pNewNode = (LNode*)malloc(sizeof(LNode));

        printf("请输入数据：");
        scanf("%d", &(pNewNode->data));

        pNewNode->next = (*ppHeadNode)->next;
        (*ppHeadNode)->next = pNewNode;
        (*ppHeadNode)->data++;
    }
    return OK;
}

// （6）创建单链表（后插）
Status createList_Tail(LinkList *ppHeadNode, int n)
{
    *ppHeadNode = (LinkList)malloc(sizeof(LNode));
    (*ppHeadNode)->next = NULL;

    LNode *pNewNode, *pTailNode;
    pTailNode = (LNode*)malloc(sizeof(LNode));
    pTailNode->next = (*ppHeadNode);
    for (int i = 0; i < n; ++i)
    {
        pNewNode = (LNode*)malloc(sizeof(LNode));
        printf("请输入数据：");
        scanf("%d", &(pNewNode->data));

        (pTailNode->next)->next = pNewNode;
        pTailNode->next = pNewNode;
        (*ppHeadNode)->data++;
    }
    pTailNode->next = NULL;
    return OK;
}
