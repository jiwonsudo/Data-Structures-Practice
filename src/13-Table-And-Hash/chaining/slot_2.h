#ifndef __SLOT_H__
#define __SLOT_H__

#include "person.h"

typedef int Key;
typedef Person *Value;

typedef struct Slot {
	Key key;
	Value value;
} Slot;

#endif