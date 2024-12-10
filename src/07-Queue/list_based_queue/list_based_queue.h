#ifndef __list_based_queue_h__
#define __list_based_queue_h__

#define TRUE 1
#define FALSE 0;

typedef int Data;

typedef struct Node {
	Data data;
	struct Node *next;
} Node;

typedef struct ListBasedQueue {
	Node *front;
	Node *rear;
} Queue;

void QueueInit(Queue *pq);
int IsQueueEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data Peek(Queue *pq);

void ExitWithErr(char msg[]);

#endif