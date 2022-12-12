#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Status.h"

/* 链队元素类型定义 */
typedef int QElemType;

// 队列元素结构
typedef struct QNode {
    QElemType data;
    struct QNode* pNext;
} QNode, * QueuePtr;

// 队列结构
typedef struct {
    QueuePtr pFront;    // 队头指针
    QueuePtr pRear;     // 队尾指针
} LinkQueue;            // 队列的链式存储表示

Status printQueue(LinkQueue Q);

// (1) 初始化 
Status initQueue(LinkQueue *pQ);

// (2) 入队
Status enQueue(LinkQueue *pQ, QElemType e);

// (3) 出队
Status deQueue(LinkQueue *pQ, QElemType *pE);

// (4) 取链队的队头元素
Status getHead(LinkQueue Q, QElemType *pE);

// (5) 队列长度
int queueLength(LinkQueue Q);

// (6) 判空
Status queueEmpty(LinkQueue Q);

// (7) 清空队列 
Status clearQueue(LinkQueue *pQ);

// (8) 销毁队列
Status destroyQueue(LinkQueue *pQ);

#endif // LINKQUEUE_H