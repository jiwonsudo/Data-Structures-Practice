#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char h_data;
typedef int (*PriorityComp)(h_data d1, h_data d2);

typedef struct Heap {
	PriorityComp comp;
	int num_of_data;
	h_data heap_arr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int IsHeapEmpty(Heap *ph);

void Insert(Heap *ph, h_data data);
h_data Delete(Heap *ph);

#endif