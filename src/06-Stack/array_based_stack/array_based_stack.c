#include <stdio.h>
#include <stdlib.h>
#include "array_based_stack.h"

void StackInit(Stack *pStack) {
	pStack->topIdx = -1;
}

Bool isStackEmpty(Stack *pStack) {
	return pStack->topIdx == -1 ? TRUE : FALSE;
}

void Push(Stack *pStack, Data data) {
	(pStack->topIdx)++;
	pStack->stackArr[pStack->topIdx] = data;
}

Data Pop(Stack *pStack) {
	if (isStackEmpty(pStack)) {
		puts("StackError: Can't pop from empty stack.");
		exit(1);
	}
	
	(pStack->topIdx)--;
	return pStack->stackArr[pStack->topIdx + 1];
}

Data Peek(Stack *pStack) {
	if (isStackEmpty(pStack)) {
		puts("StackError: Can't peek from empty stack.");
		exit(1);
	}
	
	return pStack->stackArr[pStack->topIdx];
}

// additional funcs
int getNumOfItems(Stack *pStack) {
	return (pStack->topIdx + 1);
}