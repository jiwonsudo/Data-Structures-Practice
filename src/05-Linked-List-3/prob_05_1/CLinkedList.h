#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#include "Employee.h"

#define TRUE 1;
#define FALSE 0;

typedef EData* Data;

typedef struct _node {
	Data data;
	struct _node *next;
} Node;

typedef struct _circleLinkedList {
	Node *tail;
	Node *curr;
	Node *before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LAppend(List *plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);

#endif