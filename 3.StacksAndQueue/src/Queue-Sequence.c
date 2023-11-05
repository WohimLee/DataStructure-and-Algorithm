
#include <stdlib.h>
#include <stdio.h>

#include "Queue-Sequence.h"

void printQueue(SqQueue Queue)
{
    if (!&Queue || !Queue.base){
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    if (Queue.front == Queue.rear){
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }

    int index = Queue.front;
    while(index != Queue.rear)
        printf("%d ", Queue.base[index++]);
    printf("\n");
    return OK;
}


// 1. Initialization
void initQueue(SqQueue *pQueue)
{

    pQueue->base = (ElemType*)malloc(sizeof(ElemType)*MAXQSIZE);
        if (!pQueue){
        printf("Initialize Queue Failed!\n");
        return;
    }
    if (!pQ->base)
        exit(OVERFLOW);
    
    pQ->front = pQ->rear = 0;
    return OK;
}

// (2) 求队列长度
int queueLength(SqQueue Q)
{
    if (!Q.base)
        return 0;
    
    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

// (3) 入队
Status enQueue(SqQueue *pQ, QElemType e)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }

    // 队列满的标志（浪费一个空间来区分队空和队满）
    if ((pQ->rear+1)%MAXQSIZE == pQ->front)
    {
        printf("[WARNIING]: FULL QUEUE!\n");
        return ERROR;
    }

    // 入队
    pQ->base[pQ->rear] = e;

    // 尾指针 + 1
    pQ->rear = (pQ->rear + 1) % MAXQSIZE;

    return OK;
}

// (4) 出队
Status deQueue(SqQueue *pQ, QElemType *pE)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST! \n");
        return ERROR;
    }
    // 队空的标志
    if (pQ->rear == pQ->front)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    // 出队
    *pE = pQ->base[pQ->front];

    // 头指针+1
    pQ->front = (pQ->front + 1) % MAXQSIZE;

    return OK;
}

// (5) 取队头元素
Status getHead(SqQueue Q, QElemType *pE)
{
    // 队空标志
    if (Q.front == Q.rear)
    {
        printf("[WARNING]: EMPTY QUEUE!\n");
        return ERROR;
    }
    *pE = Q.base[Q.front];
    return OK;
}

// (6) 判空
Status queueEmpty(SqQueue Q)
{
    return Q.front == Q.rear ? TRUE : FALSE;
}

// (7) 清空队列
Status clearQueue(SqQueue *pQ)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: QUEUE NOT EXIST!\n");
        return ERROR;
    }
    pQ->front = pQ->rear = 0;
    return OK;
}

// (8) 销毁队列
Status destroyQueue(SqQueue *pQ)
{
    if (!pQ || !pQ->base)
    {
        printf("[WARNING]: NOTHING TO BE DESTROYED!\n");
        return ERROR;
    }
    free(pQ->base);
    pQ->base = NULL;
    pQ->front = pQ->rear = 0;

    return ERROR;
}