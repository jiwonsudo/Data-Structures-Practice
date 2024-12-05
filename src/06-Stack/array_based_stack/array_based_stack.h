#ifndef __ARRAY_BASED_STACK_H_
#define __ARRAY_BASED_STACK_H_

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;
typedef int Bool;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIdx;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pStack);
Bool isStackEmpty(Stack *pStack);

void Push(Stack *pStack, Data data);
Data Pop(Stack *pStack);
Data Peek(Stack *pStack);

// additional funcs
int getNumOfItems(Stack *pStack);

#endif