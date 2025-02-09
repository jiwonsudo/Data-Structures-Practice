#include <stdio.h>
#include <stdlib.h>
#include "table_2.h"
#include "DLinkedList.h"

void TBLInit(Table *pt, HashFunc *func) {
	for (int i = 0; i < MAX_TABLE; i++) {
		ListInit(&(pt->table[i]));
	}
	
	pt->hash_func = func;  // resister hash function
}

void TBLInsert(Table *pt, Key key, Value value) {
	int hash_value = pt->hash_func(key);
	Slot node_slot = {key, value};
	
	if (TBLSearch(pt, key) != NULL) {  // if key is duplicated
		puts("Error: Key duplicated");
		return;
	} else {
		LInsert(&(pt->table[hash_value]), node_slot);
	}
}

Value TBLDelete(Table *pt, Key key) {
	int hash_value = pt->hash_func(key);
	Slot c_slot;
	
	if (LFirst(&(pt->table[hash_value]), &c_slot)) {
		if (c_slot.key == key) {
			LRemove(&(pt->table[hash_value]));
			return c_slot.value;
		} else {
			while (LNext(&(pt->table[hash_value]), &c_slot)) {
				if (c_slot.key == key) {
					LRemove(&(pt->table[hash_value]));
					return c_slot.value;
				}
			}
		}
	}
	
	return NULL;
}

Value TBLSearch(Table *pt, Key key) {
	int hash_value = pt->hash_func(key);
	Slot c_slot;
	
	if (LFirst(&(pt->table[hash_value]), &c_slot)) {
		if (c_slot.key == key) {
			return c_slot.value;
		} else {
			while(LNext(&(pt->table[hash_value]), &c_slot)) {
				if (c_slot.key == key) {
					return c_slot.value;
				}
			}
		}
	}
	
	return NULL;
}