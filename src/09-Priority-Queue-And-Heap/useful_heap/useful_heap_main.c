#include <stdio.h>
#include "useful_heap.h"

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;
}

int main() {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);
	
	Insert(&heap, 'A');
	Insert(&heap, 'B');
	Insert(&heap, 'C');
	printf("%c\n", Delete(&heap));
	
	Insert(&heap, 'A');
	Insert(&heap, 'B');
	Insert(&heap, 'C');
	
	printf("%c\n", Delete(&heap));
	
	puts("");
	
	while(!IsHeapEmpty(&heap)) {
		printf("%c\n", Delete(&heap));
	}
	
	return 0;
}