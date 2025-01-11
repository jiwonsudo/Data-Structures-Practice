#include "useful_heap.h"

void HeapInit(Heap *ph, PriorityComp pc) {
	ph->num_of_data = 0;
	ph->comp = pc;
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
		if (ph->comp(ph->heap_arr[GetLChildIdx(idx)],
					 ph->heap_arr[GetRChildIdx(idx)]) < 0) {
			return GetRChildIdx(idx);
		} else return GetLChildIdx(idx);
	}
}

void Insert(Heap *ph, h_data data) {
	int idx = ph->num_of_data + 1;
	
	while (idx != 1) {
		if (ph->comp(data, ph->heap_arr[GetParentIdx(idx)]) > 0) {
			ph->heap_arr[idx] = ph->heap_arr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		} else break;
	}
	
	ph->heap_arr[idx] = data;
	ph->num_of_data++;
}

h_data Delete(Heap *ph) {
	h_data ret_data = ph->heap_arr[1];
	h_data last_elem = ph->heap_arr[ph->num_of_data];
	
	int parent_idx = 1;
	int child_idx;
	
	while (child_idx = GetHigherChildIdx(ph, parent_idx)) {
		if (ph->comp(last_elem, ph->heap_arr[child_idx]) >= 0) break;
		
		ph->heap_arr[parent_idx] = ph->heap_arr[child_idx];
		parent_idx = child_idx;
	}
	
	ph->heap_arr[parent_idx] = last_elem;
	ph->num_of_data--;
	return ret_data;
}