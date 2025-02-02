#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct Person {
	int id;
	char name[STR_LEN];
	char address[STR_LEN];
} Person;

int GetID(Person *p);
void ShowPersonInfo(Person *p);
Person *MakePersonData(int id, char name[], char address[]);

#endif