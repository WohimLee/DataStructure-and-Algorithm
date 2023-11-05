#ifndef QUEUE_H
#define QUEUE_H


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
} SqQueue;

void printQueue(SqQueue Queue);

// 1. Initialization
void initQueue(SqQueue *pQueue);

// 2. Get the size of the queue
int size(SqQueue Queue);

// 3. Enter queue
void push(SqQueue *pQueue, ElemType elem);

// 4. Left Queue
ElemType pop(SqQueue *pQueue, ElemType *pElem);

// 5. Determines whether the queue is empty
bool empty(SqQueue Queue);

// 6. Clear the queue
void clear(SqQueue *pQueue);

// 7. Destroy the queue
void destroy(SqQueue *pQueue);



#endif // QUEUE_H