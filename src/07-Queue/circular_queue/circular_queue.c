#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

void QueueInit(Queue *pq) {
	pq->front = 0;
	pq->rear = 0;
}

int IsQueueEmpty(Queue *pq) {
	return pq->front == pq->rear ? TRUE : FALSE;
}

int NextPosIdx(int pos) {
	return pos == QUE_LEN - 1 ? 0 : pos + 1;  // 끝이면 0 반환(큐 회전), 아니면 다음 위치 반환
}

void Enqueue(Queue *pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front)  // 큐가 꽉 찼을 경우
		ExitWithErrMsg("Can't put data into full queue.");
	
	pq->rear = NextPosIdx(pq->rear);
	pq->que_arr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
	if (IsQueueEmpty(pq))
		ExitWithErrMsg("Can't get data from empty queue.");
	
	pq->front = NextPosIdx(pq->front);
	return pq->que_arr[pq->front];
}

Data Peek(Queue *pq) {
	if (IsQueueEmpty(pq))
		ExitWithErrMsg("Can't peek data from empty queue.");
	
	return pq->que_arr[NextPosIdx(pq->front)];
}

void ExitWithErrMsg(char msg[]) {
	printf("\nERROR: %s \n", msg);
	exit(1);
}