
#include <stdlib.h>
#include <stdio.h>

#include "Queue-Sequence.h"


// Function to print the queue.
void printQueue(SqQueue Queue) {
    if (empty(Queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contains: ");
    for (int i = Queue.front; i <= Queue.rear; i++) {
        printf("%d ", Queue.data[i]);
    }
    printf("\n");
}

// 1. Initialization
void initQueue(SqQueue *pQueue)
{

    pQueue->data = (ElemType*)malloc(sizeof(ElemType)*MAXQSIZE);
    if (!pQueue->data){
        printf("Initialize Queue Failed!\n");
        return;
    }
    pQueue->front = 0;
    pQueue->rear  = -1;
    pQueue->capacity = MAXQSIZE;
}

// 2. Get the length of the queue
int size(SqQueue Queue)
{
    return (Queue.rear - Queue.front + 1);
}

// 3. Enter queue
void push(SqQueue *pQueue, ElemType elem)
{
    if (!pQueue || !pQueue->data)
    {
        printf("[WARNING]: Queue not exist or not initialized!\n");
        return;
    }

    if (size(*pQueue) == pQueue->capacity) { // Resize if capacity reached.
        pQueue->capacity *= 2;
        pQueue->data = (ElemType *)realloc(pQueue->data, pQueue->capacity * sizeof(ElemType));
    }
    pQueue->rear++;
    pQueue->data[pQueue->rear] = elem;
    return;
}

// 4. Remove an element from the queue.
ElemType pop(SqQueue *pQueue) {
    if (empty(*pQueue)) {
        return -1; // Indicating the queue is empty.
    }
    // Retrieve the element directly without using a pointer
    ElemType elem = pQueue->data[pQueue->front];
    pQueue->front++;
    // // If needed, wrap around the front index to the beginning of the array
    // if (pQueue->front >= QUEUE_MAX_SIZE) { // Assuming QUEUE_MAX_SIZE is the size of the queue
    //     pQueue->front = 0;
    // }
    return elem;
}

// 5. Determine if the queue is empty.
bool empty(SqQueue Queue) {
    return Queue.front > Queue.rear;
}


// 6. Clear the queue.
void clear(SqQueue *pQueue) {
    pQueue->front = 0;
    pQueue->rear = -1;
}

// Function to destroy the queue.
void destroy(SqQueue *pQueue) {
    free(pQueue->data);
    pQueue->data = NULL;
    pQueue->front = 0;
    pQueue->rear = -1;
    pQueue->capacity = 0;
}