#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include "Point.h"

#define TRUE	1
#define FALSE	0

typedef Point * LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;  // 더미 노드 멤버
	Node * cur;  // 삭제, 조회에 사용
	Node * before;  // 삭제에 사용
	int numOfData;  // 데이터수
	int (*comp)(LData d1, LData d2);  // 정렬 기준을 등록하기 위한 멤버
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif