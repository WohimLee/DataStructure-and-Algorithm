#ifndef DLINKLIST_H
#define DLINKLIST_H

#include "Status.h"

typedef int ElemType;

/* 双向循环链表元素类型定义 */
typedef int ElemType;

/*
 * 双向循环链表结构
 * 注：这里的双向循环链表存在头结点
 */
typedef struct DouLNode {
    ElemType data;
    struct DouLNode* prior;  // 前驱
    struct DouLNode* next;   // 后继
} DouLNode;

// 指向双向循环链表结点的指针
typedef DouLNode* DouLinkList;

void printList(DouLinkList pL);

//（1）初始化
Status initList(DouLinkList *ppL);

//（2）插入
Status listInsert(DouLinkList pL, int i, ElemType e);

//（3）删除
Status listDelete(DouLinkList pL, int i, ElemType *pE);

//（4）查找
int locateElem(DouLinkList pL, ElemType e);

//（5）取值
Status getElem(DouLinkList pL, int i, ElemType *pE);


#endif // DLINKLIST_H