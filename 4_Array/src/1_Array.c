#include <stdarg.h> // va_list, va_start, va_end
#include "1_Array.h"

// 数组输出函数的内部实现
void Print(Array A, int dim, int index[]) {
    int i;
    if(dim == A.dim) {
        int start = 0;
        // 计算本次遍历的起始元素位置
        for(i = 0; i < dim - 1; i++) {
            start += index[i] * A.pConstants[i];
        }
        // 遍历最后一个维度内的元素
        for(i = 0; i < A.pBounds[dim - 1]; i++) {
            printf("%d ", A.pBase[start + i]);
        }
    } else {
        for(i = 0; i < A.pBounds[dim - 1]; i++) {
            printf("<");
            // 索引轮转
            index[dim - 1] = (index[dim - 1] + 1 + A.pBounds[dim - 1]) % A.pBounds[dim - 1];
            
            Print(A, dim + 1, index);
            
            printf(">");
        }
    }
}

// 按行依次输出数组中内容
void printArray(Array A) {
    int i;
    int* index;
    
    // 在遍历数组元素时，记录每个元素的索引（只记录前dim-1维）
    index = (int*) malloc((A.dim - 1) * sizeof(int));
    for(i = 0; i < A.dim - 1; i++) {
        index[i] = -1;
    }
    
    Print(A, 1, index);
    
    printf("\n");
}


// (1) 初始化
/*
     * 举例：
     * 对于三维数组 [2,3,4] 来说
     * dim = 3
     * bounds 的值为 <2,3,4>
     * constants 的值为 <12,4,1>
     * 分析 bounds，第一维中包含2个元素，第二维中包含3个元素，第三维中包含4个元素
     * 分析 constants，遍历第一维，每次需要跨过12个元素，遍历第二维，每次需要跨越4个元素，遍历第三维，每次需要跨越1个元素
     */
Status InitArray(Array *pA, int dim, ...)
{
    if (pA == NULL)
    {
        printf("[WARNING]: ARRAY NOT EXIST!\n");
        return ERROR;
    }
    if (dim < 1 || dim > MAX_ARRAY_DIM)
    {
        printf("[WARNING]: INVALID DIM!\n");
        return ERROR;
    }
    // 这是几维的数组
    pA->dim     = dim;
    // 分配存储每个维度元素的空间
    pA->pBounds = (int*)malloc(dim*sizeof(int));
    if (pA->pBounds == NULL)
        exit(OVERFLOW);
    
    // 若维度长度合法，则存入 bounds，并求出 A 的元素总数 elemtotal
    
    int elemtotal = 1;
    va_list ap;    // ap 存放可变参数表信息，指示各维度的大小
    // 使ap指向第一个可变参数，dim相当于起始标识
    va_start(ap, dim);

    for (int i = 0; i < dim; i++)
    {
        // 记录当前维度的宽度
        pA->pBounds[i] = va_arg(ap, int); // 第一次循环va_arg = dim 后面的这个参数 
        if (pA->pBounds[i] <= 0)
        {
            printf("[WARNING]: INVALID BOUNDS!\n");
            return ERROR;
        }
        // 元素总数 = dim1 * dim2 * ... *dim_n
        elemtotal *= pA->pBounds[i];
    }

    // 置空 ap
    va_end(ap);

    // 初始化数组空间，以存放元素
    pA->pBase = (ElemType*)malloc(elemtotal * sizeof(ElemType));
    if (!pA->pBase)
        exit(OVERFLOW);

    // 初始化数组空间，存放跨越的数量
    pA->pConstants = (int*)malloc(dim * sizeof(int));
    if (!pA->pConstants)
        exit(OVERFLOW);
    
    // 遍历最后一个维度，每次总是需要跨越一个元素
    pA->pConstants[dim-1] = 1;
    for(int i = dim - 2; i >= 0; i--)
        pA->pConstants[i] = pA->pBounds[i+1] * pA->pConstants[i+1];
    
    return OK;
}

// (2) 定位
static Status Locate(Array A, va_list ap, int *pOFF)
{
    *pOFF = 0;
    // dim 表示数组的维度，例如 3维, 4维
    for (int i = 0; i < A.dim; i++)
    {
        int index = va_arg(ap, int);
        // 保证不越界
        if (index < 0 || index >= A.pBounds[i])
        {
            printf("[WARNING]: OUT OF BOUND!\n");
            return OVERFLOW;
        }
        // 某个维度的单位元素个数 * 需要跨过的单位
        *pOFF += A.pConstants[i] * index;
    }
    return OK;
}

// (3) 赋值
Status Assign(Array *pA, ElemType e, ...)
{
    va_list ap;
    int off;

    va_start(ap, e);

    // 计算从起点元素到目标元素需要跨越的元素数据
    Status result = Locate(*pA, ap, &off);
    va_end(ap);
    if (result == OVERFLOW)
        return result;
    
    *(pA->pBase + off) = e;
    return OK;
}

// (4) 取值
Status Value(Array A, ElemType *e, ...)
{
    va_list ap;
    int off;

    va_start(ap, e);
    // 计算机从起点元素到目标需要跨越的元素数量
    Status result = Locate(A, ap, &off);
    va_end(ap);

    if (result == OVERFLOW)
        return result;

    *e = *(A.pBase + off);
    return OK;
}

// (5) 销毁(结构)
Status DestroyArray(Array *pA)
{
    if (!pA || !pA->pBase || !pA->pBounds || !pA->pConstants)
        return ERROR;
    free(pA->pBase);
    pA->pBase = NULL;

    free(pA->pBounds);
    pA->pBounds = NULL;

    free(pA->pConstants);
    pA->pConstants = NULL;

    pA->dim = 0;
    return OK;
}



