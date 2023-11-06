#ifndef SQLIST_H
#define SQLIST_H

#include "Status.h"

typedef int ElemType;
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10

typedef struct
{
    ElemType *data;
    int length;
    int size;
}SqList;

void printList(SqList *L);
void test_func(SqList L);

//（1）初始化
Status initList(SqList *L);
//（2）取值
Status getElem(SqList *L, int i, ElemType* e);
//（3）查找
int locateElem(SqList *L, ElemType e);
//（4）插入
Status listInsert(SqList *L, int i, ElemType e);
//（5）删除
Status listDelete(SqList *L, int i);







#endif // SQLIST_H