#include <stdio.h>
// #include "1_SqStack.h"
#include "1_SString.h"


int main()
{
    char *chars = "abc";
    SString S;
    StrAssign(S, chars);
    printElem(S);
    return 0;
}