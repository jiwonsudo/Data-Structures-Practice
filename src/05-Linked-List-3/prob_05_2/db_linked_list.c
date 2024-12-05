#include <stdio.h>
#include <stdlib.h>
#include "db_linked_list.h"

void ListInit(List *plist) {
	
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;
	
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
	if (plist->head->next == plist->tail) return FALSE;
	
	plist->curr = plist->head->next;
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->curr->next == plist->tail) return FALSE;
	
	plist->curr = plist->curr->next;  // curr을 오른쪽으로 이동
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LPrev(List *plist, Data *pdata) {
	if (plist->curr->prev == plist->head) return FALSE;
	
	plist->curr = plist->curr->prev;  // curr을 왼쪽으로 이동
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}

Data LRemove(List *plist) {
	Node *rpos = plist->curr;
	Data dataToRm = plist->curr->data;
	
	plist->curr->prev->next = plist->curr->next;
	plist->curr->next->prev = plist->curr->prev;
	
	plist->curr = plist->curr->prev;
	
	free(rpos);
	(plist->numOfData)--;
	return dataToRm;
}

int LLen(List *plist) {
	return plist->numOfData;
}