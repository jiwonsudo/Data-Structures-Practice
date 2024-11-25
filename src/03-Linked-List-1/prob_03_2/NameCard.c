#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char *name, char *phone) {
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	
	return newCard;
}

void ShowNameCardInfo(NameCard *pcard) {
	printf("네임카드 정보 | 이름: %s, 전화번호: %s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard *pcard, char *name) {
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone) {
	strcpy(pcard->phone, phone);
}