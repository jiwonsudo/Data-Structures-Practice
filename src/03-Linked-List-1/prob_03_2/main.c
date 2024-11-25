#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main() {
	List phoneBook;
	NameCard *pcard;
	ListInit (&phoneBook);
	
	pcard = MakeNameCard("JW", "010-9570-4429");
	LInsert(&phoneBook, pcard);
	
	pcard = MakeNameCard("MS", "010-2577-6977");
	LInsert(&phoneBook, pcard);
	
	pcard = MakeNameCard("EJ", "010-6404-7599");
	LInsert(&phoneBook, pcard);
	
	printf("전체 데이터 수: %d\n", LCount(&phoneBook));
	
	if (LFirst(&phoneBook, &pcard)) {
		ShowNameCardInfo(pcard);
		while(LNext(&phoneBook, &pcard)) {
			ShowNameCardInfo(pcard);
		}
	}
	
	if (LFirst(&phoneBook, &pcard)) {
		if (!NameCompare(pcard, "EJ")) {
			puts("찾은 네임카드");
			ShowNameCardInfo(pcard);
		} else {
			while(LNext(&phoneBook, &pcard)) {
				if (!NameCompare(pcard, "EJ")) {
					puts("찾은 네임카드");
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	
	if (LFirst(&phoneBook, &pcard)) {
		if (!NameCompare(pcard, "JW")) {
			ChangePhoneNum(pcard, "010-9770-4419");
		} else {
			while(LNext(&phoneBook, &pcard)) {
				if (!NameCompare(pcard, "JW")) {
					ChangePhoneNum(pcard, "010-9770-4419");
					break;
				}
			}
		}
	}
	
	if (LFirst(&phoneBook, &pcard)) {
		if (!NameCompare(pcard, "MS")) {
			pcard = LRemove(&phoneBook);
			free(pcard);
		} else {
			while(LNext(&phoneBook, &pcard)) {
				if (!NameCompare(pcard, "MS")) {
					pcard = LRemove(&phoneBook);
					free(pcard);
					break;
				}
			}
		}
	}
	
	printf("전체 데이터 수: %d\n", LCount(&phoneBook));
	
	if (LFirst(&phoneBook, &pcard)) {
		ShowNameCardInfo(pcard);
		while(LNext(&phoneBook, &pcard)) {
			ShowNameCardInfo(pcard);
		}
	}
	
	
	return 0;
}