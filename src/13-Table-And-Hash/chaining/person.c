#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int GetID(Person *p) {
	return p->id;
}

void ShowPersonInfo(Person *p) {
	printf("Personal ID: %d \n", p->id);
	printf("Name: %s \n", p->name);
	printf("Address: %s \n", p->address);
}

Person *MakePersonData(int id, char name[], char address[]) {
	Person *new_person = (Person*)malloc(sizeof(Person));
	
	new_person->id = id;
	strcpy(new_person->name, name);
	strcpy(new_person->address, address);
	
	return new_person;
}