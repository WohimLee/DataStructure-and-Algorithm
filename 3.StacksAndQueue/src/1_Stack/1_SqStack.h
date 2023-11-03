#ifndef SQSTACK_H
#define SQSTACK_H

#include "Status.h"

/* 宏定义 */
#define STACK_INIT_SIZE 100     // 顺序栈存储空间的初始分配量
#define STACKINCREMENT  10      // 顺序栈存储空间的分配增量

/* 顺序栈元素类型定义 */
typedef int SElemType;

// 顺序栈元素结构
typedef struct {
    SElemType* base; // 栈底指针
    SElemType* top;  // 栈顶指针
    int size;        // 当前已分配的存储空间，以元素为单位
} SqStack;

void printStack(SqStack S);

//（1）初始化
Status initStack(SqStack* S);

//（2）销毁（结构）
Status destroyStack(SqStack* S);

//（3）置空（内容）
Status clearStack(SqStack* S);

//（4）判空
Status stackEmpty(SqStack S);

//（5）计数
int stackLength(SqStack S);

//（6）入栈
Status push(SqStack* S, SElemType e);

//（7）出栈
Status pop(SqStack* S, SElemType* e);

//（8）取栈顶元素
SElemType getTop(SqStack S);

//（9）遍历
Status stackTraverse(SqStack S);


#endif // SQSTACK_H