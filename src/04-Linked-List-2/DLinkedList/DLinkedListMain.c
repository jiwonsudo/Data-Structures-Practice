#include <stdio.h>
#include "DLinkedList.h"

int main() {
	List list;
	int data;
	ListInit(&list);
	
	LInsert(&list, 11); LInsert(&list, 22);
	LInsert(&list, 33); LInsert(&list, 44);
	LInsert(&list, 55);
	
	printf("현재 데이터 수: %d\n", LCount(&list));
	printf("현재 데이터: ");
	
	PrintAllItems(&list);
	
	if (LFirst(&list, &data)) {
		if (data == 22) { // 22 삭제
			LRemove(&list);
		}
		
		while (LNext(&list, &data)) {
			if (data == 22) {
				LRemove(&list);
			}
		}
	}
	
	printf("현재 데이터: ");
	PrintAllItems(&list);
	
	return 0;
}