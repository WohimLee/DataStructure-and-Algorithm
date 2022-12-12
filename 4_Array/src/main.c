#include <stdarg.h>
#include "1_Array.h"



int main()
{
    Array A;
    InitArray(&A, 3, 2, 3, 4);
    ElemType e = 0;
    for (int i = 0; i < A.pBounds[0]; i++)
    {
        for (int j = 0; j < A.pBounds[1]; j++)
        {
            for (int k = 0; k < A.pBounds[2]; k++)
            {
                Assign(&A, e, i, j, k);
                e++;
            }
        }
    }
    printArray(A);
    // DestroyArray(&A);
    // printf("A[15] = %d\n", A.pBounds[1]);


    return 0;
}