#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head;  // = NULL
	if (plist->head != NULL)
		plist->head->prev = newNode;
	
	newNode->prev = NULL;
	plist->head = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
	if (plist->head == NULL) return FALSE;
	
	plist->curr = plist->head;  // curr이 첫 노드 가리키게 함
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->curr->next == NULL) return FALSE;
	
	plist->curr = plist->curr->next;  // curr을 오른쪽으로 이동
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}

int LPrev(List *plist, Data *pdata) {
	if (plist->curr->prev == NULL) return FALSE;
	
	plist->curr = plist->curr->prev;  // curr을 왼쪽으로 이동
	*pdata = plist->curr->data;  // curr이 가리키는 노드의 데이터 반환
	return TRUE;
}