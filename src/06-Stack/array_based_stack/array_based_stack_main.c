#include <stdio.h>
#include "array_based_stack.h"

int main() {
	Stack stack;
	StackInit(&stack);
	
	for (int i = 1; i < 6; i++) Push(&stack, i);
	
	printf("%d\n", getNumOfItems(&stack));
	
	while (!isStackEmpty(&stack)) printf("%d ", Pop(&stack));
	puts("");
	
	printf("%d\n", getNumOfItems(&stack));
	
	return 0;
}