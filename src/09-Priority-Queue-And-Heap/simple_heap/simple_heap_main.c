#include <stdio.h>
#include "simple_heap.h"

int main() {
	Heap heap;
	HeapInit(&heap);
	
	Insert(&heap, 'A', 1);
	Insert(&heap, 'B', 2);
	Insert(&heap, 'C', 3);
	printf("%c\n", Delete(&heap));
	
	Insert(&heap, 'A', 1);
	Insert(&heap, 'B', 2);
	Insert(&heap, 'C', 3);
	
	printf("%c\n", Delete(&heap));
	
	puts("");
	
	while(!IsHeapEmpty(&heap)) {
		printf("%c\n", Delete(&heap));
	}
	
	return 0;
}