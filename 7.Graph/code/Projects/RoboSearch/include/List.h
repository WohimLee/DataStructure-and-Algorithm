#ifndef STACK_H
#define STACK_H
typedef int ElemType;
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10

typedef struct
{
    ElemType *data;
    int length;
    int size;
}List;

void listPrint(List *L);


// 1. Initialize a list
List* listInit(List *L);

// 2. Get an element by index
ElemType listGetElem(List* pList, int index);

// 3. 
int listLocateElem(List *L, ElemType e);
//（4）插入
Status listInsert(List *L, int i, ElemType e);
//（5）删除
Status listDelete(List *L, int i);



#endif // STACK_H