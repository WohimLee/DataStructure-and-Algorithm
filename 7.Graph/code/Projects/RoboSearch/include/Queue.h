#ifndef QUEUE_H
#define QUEUE_H

/* 
    This is sequence queue implementation 
*/

#include <stdbool.h>

// Max size of a queue
#define MAXQSIZE 256

// Element type of queue
typedef int ElemType;

typedef struct {
    ElemType* data; 
    int front;      // head pointer, if queue is not empty, point to the head element
    int rear;       // rear pointer, if queue is not empty, point to the next idx of the last element
    int capacity;
} Queue;

void queuePrint(Queue Queue);

// 1. Initialization
void queueInit(Queue *pQueue);

// 2. Get the size of the queue
int queueSize(Queue Queue);

// 3. Enter queue
void queuePush(Queue *pQueue, ElemType elem);

// 4. Left Queue
ElemType queuePop(Queue *pQueue);

// 5. Determines whether the queue is empty
bool queueEmpty(Queue Queue);

// 6. Clear the queue
void queueClear(Queue *pQueue);

// 7. Destroy the queue
void queueDestroy(Queue *pQueue);



#endif // QUEUE_H