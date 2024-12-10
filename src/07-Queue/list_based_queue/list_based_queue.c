#include <stdio.h>
#include <stdlib.h>
#include "list_based_queue.h"

void QueueInit(Queue *pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int IsQueueEmpty(Queue *pq) {
	return pq->front == NULL ? TRUE : FALSE;
}

void Enqueue(Queue *pq, Data data) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	if (IsQueueEmpty(pq)) {
		pq->front = new_node;
		pq->rear = new_node;
	} else {
		pq->rear->next = new_node;
		pq->rear = new_node;
	}
}

Data Dequeue(Queue *pq) {
	Node *node_to_del;
	Data dequeued_data;
	
	if (IsQueueEmpty(pq)) ExitWithErr("Can't dequeue data from empty queue.");
	
	node_to_del = pq->front;
	dequeued_data = pq->front->data;
	pq->front = pq->front->next;
	
	free(node_to_del);
	return dequeued_data;
}

Data Peek(Queue *pq) {
	if (IsQueueEmpty(pq)) ExitWithErr("Can't peek data from empty queue.");
	
	return pq->front->data;
}

void ExitWithErr(char msg[]) {
	printf("\nUserError: %s\n", msg);
	exit(1);
}