#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist) {
	plist->tail = NULL;
	plist->curr = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LAppend(List *plist, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	(plist->numOfData)++;
}

void LInsertFront(List *plist, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->tail == NULL) {
		plist->tail == newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
	if (plist->tail == NULL) return FALSE;
	
	plist->before = plist->tail;
	plist->curr = plist->tail->next;
	
	*pdata = plist->curr->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->tail == NULL) return FALSE;
	
	plist->before = plist->curr;
	plist->curr = plist->curr->next;
	
	*pdata = plist->curr->data;
	return TRUE;
}

Data LRemove(List *plist) {
	Node *rpos = plist->curr;
	Data rdata = rpos->data;
	
	if (rpos == plist->tail) {  // 삭제 대상 == tail일 경우
		if(plist->tail == plist->tail->next) {  // 삭제 노드가 마지막 노드인 경우
			plist->tail = NULL;
		} else {
			plist->tail = plist->before;
		}
	}
	
	plist->before->next = plist->curr->next;
	plist->curr = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist) {
	return plist->numOfData;
}