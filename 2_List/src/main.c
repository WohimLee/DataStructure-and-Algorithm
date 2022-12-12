#include "4_DLinkList.h"

#include <stdlib.h>


int main()
{
    DouLinkList pL;
    initList(&pL);

    listInsert(pL, 0, 333);
    listInsert(pL, 0, 222);
    listInsert(pL, 0, 111);
    listInsert(pL, 0, 888);
    printList(pL);

    ElemType e;
    getElem(pL, 6, &e);
    // listDelete(pL, 5, &e);
    printf("e = %d\n", e);
    // printList(pL);
    // int res = locateElem(pL, 333);
    // printf("res = %d\n", res);

    return 0;
}