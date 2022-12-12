#ifndef ARRAY_H
#define ARRAY_H

#include "Status.h"

/* 宏定义 */
#define MAX_ARRAY_DIM 8 // 这里假设数组的最大维度为8

/* 数组元素类型 */
typedef int ElemType;

/* 数组的顺序存储表示 */
typedef struct {
    ElemType *pBase;    // 数组元素基址（存放数组元素）
    int dim;            // 数组维数
    int* pBounds;       // 数组维界基址（存放数组行、列信息）
    int* pConstants;    // 数组映像函数常量基址（存储遍历某个维度时，每次需要越过的元素个数）
} Array;

void Print(Array A, int dim, int index[]);
void printArray(Array A);

/* (1) 初始化
 * 初始化维数为dim的数组，可变参数指示各维度的大小。
 */
Status InitArray(Array *pA, int dim, ...);

/* (2) 定位
 * 求出ap指示的值在数组 A 中的相对位置，
 * 即计算从起点元素到目标元素需要跨越的元素数量
 */
static Status Locate(Array A, va_list ap, int *pOFF);

/* (3) 赋值
 * 为指定下标处的元素赋值，可变参数为dim个下标值，指示待赋值元素所在下标
 * 例：Assign(pA, 888, 2, 1, 2)，pA[2, 1, 2] = 888
 */
Status Assign(Array *pA, ElemType e, ...);

/* (4) 取值
 * 获取指定下标处的元素值，可变参数为dim个下标值，指示待获取元素所在下标。
 */
Status Value(Array A, ElemType* e, ...);

/* (5) 销毁(结构)
 * 销毁数组占用的空间。
 */
Status DestroyArray(Array *pA);






#endif // ARRAY_H