#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)  // 리스트 초기화
{
	plist->head = (Node*)malloc(sizeof(Node));  // 더미 노드 생성 (=head 노드)
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)  // 첫 번째 노드 생성 (dummy)
{
	Node * newNode = (Node*)malloc(sizeof(Node));  // 새 노드 생성
	newNode->data = data;  // 새 노드에 데이터 저장

	newNode->next = plist->head->next;  // 새 노드가 다른 노드를 가리키게 함
	plist->head->next = newNode;  // 더미 노드가 새노드를 가리키게 함

	(plist->numOfData)++;  // 저장된 노드의 수를 하나 증가
}

void SInsert(List * plist, LData data)  // 두 번째 이후 노드 생성
{
	Node * newNode = (Node*)malloc(sizeof(Node));  // 새 노드 생성
	Node * pred = plist->head;  // pred는 더미 노드를 가리킴
	newNode->data = data;  // 새 노드에 데이터 저장
	
	// 새 노드가 들어갈 위치를 찾기
	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)  // 다음 노드가 존재하며 comp 결과가 0이 아닐때(=newNode의 자리가 아님)
	{
		pred = pred->next;  // 다음 노드로 이동
	}

	newNode->next = pred->next;  // 새 노드의 오른쪽을 연결
	pred->next = newNode;  // 새 노드의 왼쪽을 연결

	(plist->numOfData)++;  // 저장된 데이터의 수 1 증가
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)  // 정렬기준이 마련되지 않았다면 (comp == NULL)
		FInsert(plist, data);  // 머리에 노드 추가
	else  // 정렬기준이 마련되었다면
		SInsert(plist, data);  // 정렬기준에 근거하여 노드 추가
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)  // 더미 노드(head)->next가 NULL이라면
		return FALSE;  // 반환할 데이터가 없음

	plist->before = plist->head;  // before은 더미 노드를 가리키게 함
	plist->cur = plist->head->next;  // cur은 첫 번째 노드를 가리키게 함

	*pdata = plist->cur->data;  // 첫 번째 노드의 데이터 전달
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)  // curr->next가 NULL이라면
		return FALSE;  // 반환할 데이터가 없음

	plist->before = plist->cur;  // cur이 가리키던 것을 before이 가리키도록
	plist->cur = plist->cur->next;  // cur은 현재 cur의 next를 가리킴

	*pdata = plist->cur->data;  // cur이 가리키는 노드의 데이터 전달
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;  // 소멸 대상 노드(cur)의 주소값을 rpos 노드에 저장
	LData rdata = rpos->data;  // 소멸 대상 노드의 데이터를 rdata에 저장

	plist->before->next = plist->cur->next;  // before->next를 cur->next로 변경, 소멸 대상 노드를 누락시킴
	plist->cur = plist->before;  // cur을 before로 이동

	free(rpos);  // 리스트에서 누락시킨 노드를 삭제
	(plist->numOfData)--;  // 저장된 데이터 수 1 감소
	return rdata;  // 제거된 노드 데이터 반환
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

// 조회 함수
void PrintAllItems(List *plist) {
	LData data;
	
	if (LFirst(plist, &data)) {
		printf("%d ", data);
		
		while (LNext(plist, &data)) {
			printf("%d ", data);
		}
	}
	puts("");
}

// 삭제 함수
LData LDelete(List *plist, LData dataToDelete) {
	LData data;
	
	if (LFirst(plist, &data)) {
		if (data == dataToDelete) {
			return LRemove(plist);
		}
		while (LNext(plist, &data)) {
			if (data == dataToDelete) {
				return LRemove(plist);
			}
		}
	}
	return FALSE;
}