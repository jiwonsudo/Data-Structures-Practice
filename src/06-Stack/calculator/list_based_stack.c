#include <stdio.h>
#include <stdlib.h>
#include "list_based_stack.h"

void StackInit(Stack *pstack) {
	pstack->head = NULL;
}

int IsStackEmpty(Stack *pstack) {
	return pstack->head == NULL ? TRUE : FALSE;
}

void Push(Stack *pstack, Data data) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	
	new_node->data = data;
	new_node->next = pstack->head;
	
	pstack->head = new_node;
}

Data Pop(Stack *pstack) {
	if (IsStackEmpty(pstack)) ExitWithError("Can't pop from empty stack.");
	
	Data poped_data = pstack->head->data;
	Node *node_to_rmv = pstack->head;
	pstack->head = pstack->head->next;
	
	free(node_to_rmv);
	
	return poped_data;
}

Data Peek(Stack *pstack) {
	if (IsStackEmpty(pstack)) ExitWithError("Can't pop from empty stack.");
	
	return pstack->head->data;
}

void ExitWithError(char *msg) {
	printf("ERROR: %s\n", msg);
	exit(1);
}