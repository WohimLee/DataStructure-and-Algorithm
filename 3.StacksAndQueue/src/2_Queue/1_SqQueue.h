#ifndef SQQUEUE_H
#define SQQUEUE_H

#include "Status.h"

/* 宏定义 */
#define MAXQSIZE 1000   //最大队列长度

/* 循环队列元素类型定义 */
typedef int QElemType;

// 循环队列的顺序存储结构
typedef struct {
    QElemType* base;    // 动态分配存储空间
    int front;          // 头指针，若队列不空，指向队头元素
    int rear;           // 尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

Status printQueue(SqQueue Q);

// (1) 初始化
Status initQueue(SqQueue *pQ);

// (2) 求队列长度
int queueLength(SqQueue Q);

// (3) 入队
Status enQueue(SqQueue *pQ, QElemType e);

// (4) 出队
Status deQueue(SqQueue *pQ, QElemType *pE);

// (5) 取队头元素
Status getHead(SqQueue Q, QElemType *pE);

// (6) 判空
Status queueEmpty(SqQueue Q);

// (7) 清空队列
Status clearQueue(SqQueue *pQ);

// (8) 销毁队列
Status destroyQueue(SqQueue *pQ);

#endif // SQQUEUE_H