#include <stdlib.h>
#include "1_SqList.h"

void printList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}


void test_func(SqList L)
{
    L.length = 12;
}


// （1）初始化
Status initList(SqList *L)
{
    L->data = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->data)
        exit(OVERFLOW);
    L->length = 0;
    L->size   = LIST_INIT_SIZE;
    return OK;
}

// （2）取值
Status getElem(SqList *L, int i, ElemType* e)
{
    if (i < 1 || i > L->length)
        return ERROR;
    printf("%d\n", L->data[i]);
    *e = L->data[i];
    return OK;
}

// （3）查找
int locateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
            return i;
    }
    return 0;
}

// （4）插入
Status listInsert(SqList *L, int i, ElemType e)
{
    if (&L == NULL)
        return ERROR;
      
    if (i < 0 || i > (L->length))
        return ERROR;
        
    // 如果容量满了，重新分配内存
    ElemType* newbase;
    if (L->length >= L->size)
    {
        newbase = (ElemType*)realloc(L->data, (L->size+LISTINCREMENT)*sizeof(ElemType));
        if (newbase == NULL)
            exit(OVERFLOW);
        L->data = newbase;
        L->size += LISTINCREMENT;
    }

    ElemType *insert_cur, *move_cur;
    // p1 为插入位置
    insert_cur = &(L->data[i]);
    for (move_cur = &(L->data[L->length]); move_cur >= insert_cur; --move_cur)
        *(move_cur + 1) = *move_cur; // 逐个元素后移

    *insert_cur = e;
    L->length++;
    return OK;
}

// （5）删除
Status listDelete(SqList* L, int i)
{
    if (L == NULL || L->data == NULL)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    ElemType *move_cur, *end_cur;
    move_cur = &(L->data[i]);          // 被删除元素的位置
    end_cur  = &L->data[L->length]; // 表尾元素位置

    for (move_cur; move_cur <= end_cur; ++move_cur)
        *move_cur = *(move_cur+1);

    L->length--;
    return OK;
}



