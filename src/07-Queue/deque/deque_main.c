#include <stdio.h>
#include "deque.h"

int main() {
	Deque deq;
	DequeInit(&deq);
	
	Insert(&deq, 3);
	Insert(&deq, 2);
	Insert(&deq, 1);
	
	Append(&deq, 4);
	Append(&deq, 5);
	Append(&deq, 6);
	
	while(!IsDequeEmpty(&deq)) {
		printf("%d ", Remove(&deq));
	}
	
	puts("");
	
	Insert(&deq, 3);
	Insert(&deq, 2);
	Insert(&deq, 1);
	
	Append(&deq, 4);
	Append(&deq, 5);
	Append(&deq, 6);
	
	while(!IsDequeEmpty(&deq)) {
		printf("%d ", Pop(&deq));
	}
	
	puts("");
	
	return 0;
}