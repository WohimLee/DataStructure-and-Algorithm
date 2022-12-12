#include "5_LinkQueue.h"
#include <stdlib.h>
#include <stdio.h>


Status printQueue(LinkQueue Q)
{
    if (!Q.pFront)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    if (Q.pFront == Q.pRear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }

    QNode *pMove = Q.pFront->pNext;
    while (pMove)
    {
        printf("%d ", pMove->data);
        pMove = pMove->pNext;
    }
    printf("\n");

    return OK;
}

// (1) 初始化 
Status initQueue(LinkQueue *pQ)
{
    if (!pQ)
        return ERROR;
    // 创建头结点，pQ->pFront 与 pQ->pRear 都指向头结点
    pQ->pFront = pQ->pRear = (QNode*)malloc(sizeof(QNode));
    if (!pQ->pFront)
        exit(OVERFLOW);
    pQ->pFront->pNext = NULL;
    return OK;
}

// (2) 入队
Status enQueue(LinkQueue *pQ, QElemType e)
{
    if (!pQ || !pQ->pFront)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    QNode *pNew = (QNode*)malloc(sizeof(QNode));
    if (!pNew)
        exit(OVERFLOW);
    
    pNew->data  = e;
    pNew->pNext = NULL;

    // 此时 pQ->pRear 就等于队尾结点
    pQ->pRear->pNext = pNew;
    pQ->pRear = pNew;

    return OK;
}

// (3) 出队
Status deQueue(LinkQueue *pQ, QElemType *pE)
{
    if (!pQ || pQ->pFront == NULL)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    if (pQ->pFront == pQ->pRear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    // 取值
    QNode *pMove = pQ->pFront->pNext; // pMove = 队头结点
    *pE = pMove->data;

    // 出队
    // 更改头结点的 pNext 为 pMove 的 next 
    pQ->pFront->pNext = pMove->pNext;
    // 如果出队的是队尾结点
    if (pQ->pRear == pMove)
    {
        pQ->pRear = pQ->pFront;
    }

    free(pMove);

    return OK;
}

// (4) 取链队的队头元素
Status getHead(LinkQueue Q, QElemType *pE)
{
    if (!Q.pFront)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    if (Q.pFront == Q.pRear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    *pE = Q.pFront->pNext->data;
    return OK;
}

// (5) 队列长度
int queueLength(LinkQueue Q)
{
    if (!Q.pFront)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    if (Q.pFront == Q.pRear)
    {
        return 0;
    }
    QNode *pMove = Q.pFront;
    int count = 0;
    // while (pMove->pNext)
    while (pMove != Q.pRear)
    {
        count++;
        pMove = pMove->pNext;
    }
    return count;
}

// (6) 判空
Status queueEmpty(LinkQueue Q)
{
    return Q.pFront == Q.pRear ? TRUE : FALSE;
}

// (7) 清空队列，变成空队列 
Status clearQueue(LinkQueue *pQ)
{
    if (!pQ)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    // 先把 pRear 指向队头结点
    pQ->pRear = pQ->pFront->pNext;

    while (pQ->pRear)
    {
        // 更改队头结点
        pQ->pFront->pNext = pQ->pRear->pNext;
        // 用 pRear 指针释放头结点
        free(pQ->pRear);
        // 再把 pRear 指向新的队头结点
        pQ->pRear = pQ->pFront->pNext;
    }
    pQ->pRear = pQ->pFront;

    return OK;
}

// (8) 销毁队列
Status destroyQueue(LinkQueue *pQ)
{
    if (!pQ)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    while(pQ->pFront)
    {
        pQ->pRear = pQ->pFront->pNext;
        free(pQ->pFront);
        pQ->pFront = pQ->pRear;
    }
    return OK;
}