#include <stdio.h>
#include "DLinkedList.h"

int isFirstArgFirst(int d1, int d2){
	if (d1 < d2)
		return 0;  // d1 goes first
	else
		return 1;  // d2 goes first
}

int main() {
	List list;
	int data;
	ListInit(&list);
	
	SetSortRule(&list, isFirstArgFirst);  // 정렬기준등록
	
	LInsert(&list, 11); LInsert(&list, 22);
	LInsert(&list, 33); LInsert(&list, 22);
	LInsert(&list, 11);
	
	printf("현재 데이터 수: %d\n", LCount(&list));
	printf("현재 데이터: "); PrintAllItems(&list);
	
	LDelete(&list, 33);	
	
	printf("현재 데이터 수: %d\n", LCount(&list));
	printf("현재 데이터: "); PrintAllItems(&list);
	
	LDelete(&list, 22);
	
	printf("현재 데이터 수: %d\n", LCount(&list));
	printf("현재 데이터: "); PrintAllItems(&list);
	
	return 0;
}