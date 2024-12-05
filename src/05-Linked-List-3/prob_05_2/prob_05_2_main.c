#include <stdio.h>
#include "db_linked_list.h"

int main() {
	List list;
	int data;
	ListInit(&list);
	
	for (int i = 1; i < 9; i++) LInsert(&list, i);
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
		puts("");
	}
	
	if (LFirst(&list, &data)) {
		if (data % 2 == 0) LRemove(&list);
		
		while (LNext(&list, &data)) {
			if (data % 2 == 0) LRemove(&list);
		}
	}
	
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
		puts("");
	}
	
	return 0;
}