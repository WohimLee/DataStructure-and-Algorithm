#ifndef STACK_H
#define STACK_H

/*
    This is a sequence list implementation
*/

#include <stdbool.h>
#include "Status.h"


#define STACK_INIT_SIZE 128 // Init size
#define STACKINCREMENT  16  // Increment for full stack

// Data type of element in stack
typedef int StackElemType;

// Data Structure of stack
typedef struct {
    StackElemType* base; // bottom pointer
    StackElemType* top;  // top pointer
    int capacity;        // capacity of stack
}Stack;

void stackPrint(Stack stack);

// 1. Initialize stack
Stack* stackInit();

// 2. Determin if the stack is empty
bool stackEmpty(Stack stack);

// 3. Push an element in stack
void stackPush(Stack* pStack, const StackElemType elem);

// 4. Pop out an element from stack
StackElemType stackPop(Stack* S);

// 5. Get the length of stack
int stackSize(const Stack S);

// 6. Clear the content of stack
void stackClear(Stack* pStack);

// 7. Destroy a stack
void stackDestroy(Stack* pStack);

#endif // STACK_H