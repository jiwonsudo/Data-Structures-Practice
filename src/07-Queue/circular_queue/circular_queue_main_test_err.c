#include <stdio.h>
#include "circular_queue.h"

int main() {
	Queue q;
	QueueInit(&q);
	
	for (int i = 1; i < 6; i++) Enqueue(&q, i);
	
	while (1) printf("%d ", Dequeue(&q));
	puts("");
	
	return 0;
}