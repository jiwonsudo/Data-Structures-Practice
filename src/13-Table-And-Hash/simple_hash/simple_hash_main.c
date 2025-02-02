#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "table.h"

int MyHashFunc(int key) {
	return key % 100;
}

int main(void) {
	Table my_table;
	Person *data_to_init;
	Person *data_to_search;
	Person *data_to_remove;
	
	TBLInit(&my_table, MyHashFunc);
	
	// input data
	data_to_init = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&my_table, GetID(data_to_init), data_to_init);
	
	data_to_init = MakePersonData(20130012, "Kim", "Daegu");
	TBLInsert(&my_table, GetID(data_to_init), data_to_init);
	
	data_to_init = MakePersonData(20170049, "Han", "Busan");
	TBLInsert(&my_table, GetID(data_to_init), data_to_init);
	
	// Search Data
	data_to_search = TBLSearch(&my_table, 20120003);
	if (data_to_search != NULL) ShowPersonInfo(data_to_search);
	
	data_to_search = TBLSearch(&my_table, 20130012);
	if (data_to_search != NULL) ShowPersonInfo(data_to_search);
	
	data_to_search = TBLSearch(&my_table, 20170049);
	if (data_to_search != NULL) ShowPersonInfo(data_to_search);
	
	// Remove Data
	data_to_remove = TBLDelete(&my_table, 20120003);
	if (data_to_remove != NULL) free(data_to_remove);
	
	data_to_remove = TBLDelete(&my_table, 20130012);
	if (data_to_remove != NULL) free(data_to_remove);
	
	data_to_remove = TBLDelete(&my_table, 20170049);
	if (data_to_remove != NULL) free(data_to_remove);
	
	return 0;
}