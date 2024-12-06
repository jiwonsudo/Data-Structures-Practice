#include <stdio.h>
#include "linked_list_based_stack.h"

int main() {
	Stack stack;
	StackInit(&stack);
	
	for (int i = 1; i < 6; i++) Push(&stack, i);
	
	while (!IsStackEmpty(&stack)) printf("%d ", Pop(&stack));
	
	return 0;
}