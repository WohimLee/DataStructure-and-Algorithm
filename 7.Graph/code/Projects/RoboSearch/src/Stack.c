

#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>


// Print the stack elements
void stackPrint(Stack stack) {
    if (stackEmpty(stack)) {
        printf("The stack is empty.\n");
        return;
    }
    StackElemType *p = stack.base;
    printf("Stack remains:");
    while (p != stack.top) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

// 1. Initialize stack
Stack* stackInit() {
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (!pStack) {
        exit(OVERFLOW);  // Exit if memory allocation fails
    }
    pStack->base = (StackElemType*)malloc(STACK_INIT_SIZE * sizeof(StackElemType));
    if (!pStack->base) {
        exit(OVERFLOW);
    }
    pStack->top = pStack->base;
    pStack->capacity = STACK_INIT_SIZE;
    return pStack;
}

// 2. Determine if the stack is empty
bool stackEmpty(Stack stack) {
    return stack.base == stack.top;
}

// 3. Push an element into the stack
void stackPush(Stack* pStack, const StackElemType elem) {
    if (pStack->top - pStack->base >= pStack->capacity) {
        pStack->base = (StackElemType *)realloc(pStack->base, (pStack->capacity + STACKINCREMENT) * sizeof(StackElemType));
        if (!pStack->base) {
            exit(OVERFLOW);
        }
        pStack->top = pStack->base + pStack->capacity;
        pStack->capacity += STACKINCREMENT;
    }
    *(pStack->top) = elem;
    pStack->top++;
    // printf("Push %d in stack\n", elem);
}

// 4. Pop an element out of the stack
StackElemType stackPop(Stack* pStack) {
    if (pStack->top == pStack->base) {
        printf("The stack is empty, cannot pop!\n");
        exit(UNDERFLOW);  // Stack is empty, cannot pop
    }
    pStack->top--;
    // printf("Pop %d out of statck\n", *(pStack->top));
    return *(pStack->top);
}

// 5. Get the length of the stack
int stackSize(const Stack S) {
    return S.top - S.base;
}



// Clear the content of stack
void stackClear(Stack* pStack) {
    pStack->top = pStack->base;
}

// Destroy a stack
void stackDestroy(Stack* pStack) {
    free(pStack->base);
    pStack->base = NULL;
    pStack->top = NULL;
    pStack->capacity = 0;
    free(pStack);
}