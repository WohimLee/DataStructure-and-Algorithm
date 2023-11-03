#ifndef SLINKLIST
#define SLINKLIST

#include "Status.h"

/* 单链表元素类型定义 */
typedef int ElemType;

/*
 * 单链表结构
 * 注：这里的单链表存在头结点
 */
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向单链表结点的指针
typedef LNode* LinkList;

void printList(LinkList pL);

// （1）初始化
Status initList(LinkList *ppL);

// （2）取值
Status getElem(LinkList pL, int i, ElemType *pE);

// （3）查找
LNode *locateElem(LinkList pL, ElemType e);

// （4）插入
Status listInsert(LinkList pL, int i, ElemType e);

// （5）删除
Status listDelete(LinkList pL, int i, ElemType *e);

// （6）创建单链表（前插）
Status createList_Head(LinkList *ppHeadNode, int n);

// （6）创建单链表（后插）
Status createList_Tail(LinkList *ppHeadNode, int n);

#endif // SLINKLIST