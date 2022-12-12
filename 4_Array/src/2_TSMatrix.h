#ifndef TSMATRIX_H
#define TSMATRIX_H

/* 宏定义 */
#define MAXSIZE 12500   // 非零元数量的最大值

/* 三元组稀疏矩阵元素类型 */
typedef int ElemType;

/* 三元组类型定义，主要用来存储非零元 */
typedef struct {
    int i, j;       // 该三元组非零元的行下标和列下标
    ElemType e;
} Triple;

/* 三元组稀疏矩阵类型定义 */
typedef struct {
    Triple data[MAXSIZE + 1];   // 非零元三元组表，data[0]未用
    int mu, nu, tu;             // 矩阵的行数、列数和非零元个数
} TSMatrix;


#endif // TSMATRIX_H