#include <stdio.h>
#include "CLinkedList.h"

int main() {
	List list;
	int data, numOfNode;
	ListInit(&list);
	
	LAppend(&list, 3); LAppend(&list, 4);
	LAppend(&list, 5); LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		for (int i = 0; i < LCount(&list) * 3 - 1; i++) {
			if (LNext(&list, &data)) printf("%d ", data);
		}
	}
	puts("");
	
	// 2의 배수 모두 삭제
	numOfNode = LCount(&list);
	
	if (numOfNode != 0) {
		LFirst(&list, &data);
		if (data % 2 == 0) LRemove(&list);
		
		for (int i = 0; i < numOfNode-1; i++) {
			LNext(&list, &data);
			if (data % 2 == 0) LRemove(&list);
		}
	}
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		for (int i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data)) printf("%d ", data);
		}
	}
	puts("");
	
	return 0;
}