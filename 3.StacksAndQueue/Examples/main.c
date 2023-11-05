
#include <stdio.h>
#include "Test.h"

int main(int argc, char** argv)
{

    SqQueue queue;
    initQueue(&queue);
    printf("Length of queue: %d\n", size(queue));


    return 0;
}