#ifndef __TABLE_H__
#define __TABLE_H__

#include "slot.h"

#define MAX_TABLE 100

typedef int HashFunc(Key);

typedef struct Table {
	Slot table[MAX_TABLE];
	HashFunc *hash_func;
} Table;

// initialization of table
void TBLInit(Table *pt, HashFunc *func);

// store key and value in a table
void TBLInsert(Table *pt, Key key, Value value);

// delete data in table by key
Value TBLDelete(Table *pt, Key key);

// search data in table by key
Value TBLSearch(Table *pt, Key key);

#endif