#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Node {
	Data data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Deque {
	Node *head;
	Node *tail;
} Deque;

void DequeInit(Deque *pdeq);
int IsDequeEmpty(Deque *pdeq);

void Insert(Deque *pdeq, Data data);  // add data at head
void Append(Deque *pdeq, Data data);  // add data at tail

Data Remove(Deque *pdeq);  // remove & return first data 
Data Pop(Deque *pdeq);  // remove & return last data

Data PeekHead(Deque *pdeq);
Data PeekTail(Deque *pdeq);

void ExitWithError(char msg[]);

#endif