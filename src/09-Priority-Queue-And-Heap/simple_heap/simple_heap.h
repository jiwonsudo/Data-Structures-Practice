#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char h_data;
typedef int priority;

typedef struct HeapElem {
	priority pr;
	h_data data;
} HeapElem;

typedef struct Heap {
	int num_of_data;
	HeapElem heap_arr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int IsHeapEmpty(Heap *ph);

void Insert(Heap *ph, h_data data, priority pr);
h_data Delete(Heap *ph);

#endif