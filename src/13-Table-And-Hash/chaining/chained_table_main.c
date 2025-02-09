#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "table_2.h"

int MyHashFunc(int key) {
	return key % 100;
}

int main(void) {
	Table my_table;
	Person *np;
	Person *sp;
	Person *rp;
	
	TBLInit(&my_table, MyHashFunc);
	
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&my_table, GetID(np), np);
	
	np = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&my_table, GetID(np), np);
	
	np = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&my_table, GetID(np), np);
	
	sp = TBLSearch(&my_table, 900254);
	sp != NULL ? ShowPersonInfo(sp) : 0;
	
	sp = TBLSearch(&my_table, 900139);
	sp != NULL ? ShowPersonInfo(sp) : 0;
	
	sp = TBLSearch(&my_table, 900827);
	sp != NULL ? ShowPersonInfo(sp) : 0;
	
	rp = TBLDelete(&my_table, 900254);
	rp != NULL ? free(rp) : puts("DeleteError");
	
	rp = TBLDelete(&my_table, 900139);
	rp != NULL ? free(rp) : puts("DeleteError");
	
	rp = TBLDelete(&my_table, 900827);
	rp != NULL ? free(rp) : puts("DeleteError");
	
	return 0;
}