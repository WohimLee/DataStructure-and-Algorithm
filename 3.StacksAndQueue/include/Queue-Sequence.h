#ifndef QUEUE_SEQUENCE_H
#define QUEUE_SEQUENCE_H

#include "Status.h"

// Max size of a queue
#define MAXQSIZE 1000 

// Element type of queue
typedef int ElemType;

// 循环队列的顺序存储结构
typedef struct {
    ElemType* base; // 动态分配存储空间
    int front;      // head pointer, if queue is not empty, point to the head element
    int rear;       // rear pointer, if queue is not empty, point to the next idx of the last element
} SqQueue;

Status printQueue(SqQueue Queue);

// 1. Initialization
Status initQueue(SqQueue *pQueue);

// 2. Get the length of the queue
int queueLength(SqQueue Queue);

// 3. Enter queue
Status enQueue(SqQueue *pQueue, ElemType elem);

// 4. Left Queue
Status deQueue(SqQueue *pQueue, ElemType *pElem);

// 5. Get the head element
Status getHead(SqQueue Queue, ElemType *pElem);

// 6. Determines whether the queue is empty
Status isEmpty(SqQueue Queue);

// 7. Clear the queue
Status clear(SqQueue *pQueue);

// 8. Destroy the queue
Status destroy(SqQueue *pQueue);

#endif // QUEUE_SEQUENCE_H