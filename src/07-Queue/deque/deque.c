#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void DequeInit(Deque *pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

void ExitWithError(char msg[]) {
	printf("\nError: %s\n", msg);
	exit(1);
}

int IsDequeEmpty(Deque *pdeq) {
	return pdeq->head == NULL ? TRUE : FALSE;
}

void Insert(Deque *pdeq, Data data) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = pdeq->head;
	
	if(IsDequeEmpty(pdeq)) {
		pdeq->tail = new_node;
	} else {
		pdeq->head->prev = new_node;
	}
	
	new_node->prev = NULL;
	pdeq->head = new_node;
}

void Append(Deque *pdeq, Data data) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->prev = pdeq->tail;
	
	if(IsDequeEmpty(pdeq)) {
		pdeq->head = new_node;
	} else {
		pdeq->tail->next = new_node;
	}
	
	new_node->next = NULL;
	pdeq->tail = new_node;
}

Data Remove(Deque *pdeq) {
	Node *node_to_rm = pdeq->head;
	Data data_to_rm;
	if(IsDequeEmpty(pdeq)) ExitWithError("Can't Remove 1st node from empty deque.");
	
	data_to_rm = node_to_rm->data;
	pdeq->head = pdeq->head->next;
	free(node_to_rm);
	
	if(pdeq->head == NULL) {
		pdeq->tail = NULL;
	} else {
		pdeq->head->prev == NULL;
	}
	
	return data_to_rm;
}

Data Pop(Deque *pdeq) {
	Node *node_to_rm = pdeq->tail;
	Data data_to_rm;
	if(IsDequeEmpty(pdeq)) ExitWithError("Can't Pop last node from empty deque.");
	
	data_to_rm = node_to_rm->data;
	pdeq->tail = pdeq->tail->prev;
	free(node_to_rm);
	
	if(pdeq->tail = NULL) {
		pdeq->head = NULL;
	} else {
		pdeq->tail->next == NULL;
	}
	
	return data_to_rm;
}

Data PeekHead(Deque *pdeq) {
	if(IsDequeEmpty(pdeq)) ExitWithError("Can't Peek 1st node from empty deque.");
	return pdeq->head->data;
}

Data PeekTail(Deque *pdeq) {
	if(IsDequeEmpty(pdeq)) ExitWithError("Can't Peek last node from empty deque.");
	return pdeq->tail->data;
}

