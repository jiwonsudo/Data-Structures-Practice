#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

EData* GetNightDutyAfter(List *plist, char *nameToday, int dayAfter);
EData* FindEDataWithName(List *plist, char *name);
void PrintEDataInfo(EData *dataToPrint);

int main() {
	List list;
	ListInit(&list);
	
	EData *data;
	
	data = (EData*)malloc(sizeof(EData));
	data->number = 12415;
	strcpy(data->name, "Jiwon");
	LAppend(&list, data);
	
	data = (EData*)malloc(sizeof(EData));
	data->number = 44227;
	strcpy(data->name, "Minseong");
	LAppend(&list, data);
	
	data = (EData*)malloc(sizeof(EData));
	data->number = 92110;
	strcpy(data->name, "Ryeongeun");
	LAppend(&list, data);
	
	data = GetNightDutyAfter(&list, "Jiwon", 2);
	PrintEDataInfo(data);
	
	data = GetNightDutyAfter(&list, "Minseong", 5);
	PrintEDataInfo(data);
	
	if (LFirst(&list, &data)) {
		free(data);
		for (int i = 0; i < LCount(&list)-1; i++) {
			if (LNext(&list, &data)) free(data);
		}
	}
	
	return 0;
}

EData* GetNightDutyAfter(List *plist, char *nameToday, int dayAfter) {
	EData *searchedData;
	
	if (FindEDataWithName(plist, nameToday) != NULL) {
		for (int i = 0; i < dayAfter; i++) {
			LNext(plist, &searchedData);
		}
		return searchedData;
	}
	
	return NULL;
}

EData* FindEDataWithName(List *plist, char *name) {
	EData *dataToCompare;
	int numOfData = LCount(plist);
	int i;
	
	LFirst(plist, &dataToCompare);
	
	if (strcmp(dataToCompare->name, name) != 0) {
		for (i = 0; i < numOfData-1; i++) {
			LNext(plist, &dataToCompare);
			if (strcmp(dataToCompare->name, name) == 0)
				return dataToCompare;
		}
		
		if (i >= numOfData-1) return NULL;  // 해당 이름 미존재
	} else return dataToCompare;
}

void PrintEDataInfo(EData *dataToPrint) {
	printf("Employee No. %i ", dataToPrint->number);
	printf("Name: %s \n", dataToPrint->name);
}