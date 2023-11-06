#ifndef STACK_SEQUENCE_H
#define STACK_SEQUENCE_H


#include <stdbool.h>


#define STACK_INIT_SIZE 100 // Init size
#define STACKINCREMENT  10  // Increment for full stack

// Data type of element in stack
typedef int StackElemType;

// Data Structure of stack
typedef struct {
    StackElemType* base; // bottom pointer
    StackElemType* top;  // top pointer
    int capacity;        // capacity of stack
} SqStack;

void stackPrint(SqStack stack);

// 1. Initialize stack
SqStack* stackInit();

// 2. Determin if the stack is empty
bool stackEmpty(SqStack stack);

// 3. Push an element in stack
void stackPush(SqStack* pStack, const StackElemType elem);

// 4. Pop out an element from stack
StackElemType stackPop(SqStack* S);

// 5. Get the length of stack
int stackSize(const SqStack S);

// 6. Clear the content of stack
void stackClear(SqStack* pStack);

// 7. Destroy a stack
void stackDestroy(SqStack* pStack);



#endif // STACK_SEQUENCE_H