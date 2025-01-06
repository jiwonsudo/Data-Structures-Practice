#include "simple_heap.h"

void HeapInit(Heap *ph) {
	ph->num_of_data = 0;
}

int IsHeapEmpty(Heap *ph) {
	return ph->num_of_data == 0 ? TRUE : FALSE;
}

int GetParentIdx(int idx) {
	return idx / 2;
}

int GetLChildIdx(int idx) {
	return idx * 2;
}

int GetRChildIdx(int idx) {
	return idx * 2 + 1;
}

int GetHigherChildIdx(Heap *ph, int idx) {
	if (GetLChildIdx(idx) > ph->num_of_data) {
		return 0;
	} else if (GetLChildIdx(idx) == ph->num_of_data) {
		return GetLChildIdx(idx);
	} else {
		if (ph->heap_arr[GetLChildIdx(idx)].pr > ph->heap_arr[GetRChildIdx(idx)].pr) {
			return GetRChildIdx(idx);
		} else return GetLChildIdx(idx);
	}
}

void Insert(Heap *ph, h_data data, priority pr) {
	int idx = ph->num_of_data + 1;
	HeapElem nelem = {pr, data};
	
	while (idx != 1) {
		if (pr < ph->heap_arr[GetParentIdx(idx)].pr) {
			ph->heap_arr[idx] = ph->heap_arr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		} else break;
	}
	
	ph->heap_arr[idx] = nelem;
	ph->num_of_data++;
}

h_data Delete(Heap *ph) {
	h_data ret_data = ph->heap_arr[1].data;
	HeapElem last_elem = ph->heap_arr[ph->num_of_data];
	
	int parent_idx = 1;
	int child_idx;
	
	while (child_idx = GetHigherChildIdx(ph, parent_idx)) {
		if (last_elem.pr <= ph->heap_arr[child_idx].pr) break;
		
		ph->heap_arr[parent_idx] = ph->heap_arr[child_idx];
		parent_idx = child_idx;
	}
	
	ph->heap_arr[parent_idx] = last_elem;
	ph->num_of_data--;
	return ret_data;
}