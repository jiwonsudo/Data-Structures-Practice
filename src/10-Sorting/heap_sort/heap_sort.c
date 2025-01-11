#include <stdio.h>
#include "useful_heap.h"

int PriComp(int n1, int n2) {
	return n2 - n1;
}

void HeapSort(int arr[], int len, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);
	
	for (int i = 0; i < len; i++)
		Insert(&heap, arr[i]);
	for (int i = 0; i < len; i++)
		arr[i] = Delete(&heap);
}

int main() {
	int arr[4] = {3, 4, 2, 1};
	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);
	
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	
	puts("");
	return 0;
}