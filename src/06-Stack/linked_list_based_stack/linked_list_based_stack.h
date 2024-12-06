#ifndef __LINKED_LIST_BASED_STACK_H__
#define __LINKED_LIST_BASED_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
} Node;

typedef struct ListStack {
	Node *head;
} Stack;

void StackInit(Stack *pstack);
int IsStackEmpty(Stack *pstack);

void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);

void ExitWithError(char *msg);

#endif