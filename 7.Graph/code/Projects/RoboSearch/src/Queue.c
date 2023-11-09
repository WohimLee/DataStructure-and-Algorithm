
#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

// Function to print the queue.
void queuePrint(Queue Queue) {
    if (queueEmpty(Queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue remains: ");
    for (int i = Queue.front; i <= Queue.rear; i++) {
        printf("%d ", Queue.data[i]);
    }
    printf("\n");
}

// 1. Initialization
void queueInit(Queue *pQueue)
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
int queueSize(Queue Queue)
{
    return (Queue.rear - Queue.front + 1);
}

// 3. Enter queue
void queuePush(Queue *pQueue, ElemType elem)
{
    if (!pQueue || !pQueue->data)
    {
        printf("[WARNING]: Queue not exist or not initialized!\n");
        return;
    }

    if (queueSize(*pQueue) == pQueue->capacity) { // Resize if capacity reached.
        pQueue->capacity *= 2;
        pQueue->data = (ElemType *)realloc(pQueue->data, pQueue->capacity * sizeof(ElemType));
    }
    pQueue->rear++;
    pQueue->data[pQueue->rear] = elem;
    // printf("\nPush %d in queue\n", elem);
    return;
}

// 4. Remove an element from the queue.
ElemType queuePop(Queue *pQueue) {
    if (queueEmpty(*pQueue)) {
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
bool queueEmpty(Queue Queue) {
    return Queue.front > Queue.rear;
}


// 6. Clear the queue.
void queueClear(Queue *pQueue) {
    pQueue->front = 0;
    pQueue->rear = -1;
}

// Function to destroy the queue.
void queueDestroy(Queue *pQueue) {
    free(pQueue->data);
    pQueue->data = NULL;
    pQueue->front = 0;
    pQueue->rear = -1;
    pQueue->capacity = 0;
}