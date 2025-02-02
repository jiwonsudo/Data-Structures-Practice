#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void TBLInit(Table *pt, HashFunc *func) {
	// initialize every slot
	for (int i = 0; i < MAX_TABLE; i++) {
		(pt->table[i]).status = EMPTY;
	}
	
	pt->hash_func = func;  // resister hash function
}

void TBLInsert(Table *pt, Key key, Value value) {
	int hash_value = pt->hash_func(key);
	pt->table[hash_value].value = value;
	pt->table[hash_value].key = key;
	pt->table[hash_value].status = INUSE;
}

Value TBLDelete(Table *pt, Key key) {
	int hash_value = pt->hash_func(key);
	
	if ((pt->table[hash_value]).status != INUSE) {
		return NULL;
	} else {
		(pt->table[hash_value]).status = DELETED;
		return (pt->table[hash_value].value);  // return value of deleted data
	}
}

Value TBLSearch(Table *pt, Key key) {
	int hash_value = pt->hash_func(key);
	
	if ((pt->table[hash_value]).status != INUSE) {
		return NULL;
	} else {
		return (pt->table[hash_value]).value;  // return value of searched data
	}
}