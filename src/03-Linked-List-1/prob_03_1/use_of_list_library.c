#include <stdio.h>
#include "ArrayList.h"

int main() {
	List list;  // 리스트 생성
	ListInit(&list);  // 리스트 초기화
	int data;  // 데이터 저장
	int sum;  // 합 계산
	
	// 정수 1 ~ 9까지 리스트 저장
	for (int i = 1; i < 10; i++) {
		LInsert(&list, i);
	}
	
	// 배열 0번 ~ 끝번 인덱스 sum에 저장
	if (LFirst(&list, &data)) {
		sum = sum + data;
		
		while (LNext(&list, &data)) {
			sum = sum + data;
		}
	}
	
	printf("배열의 총합: %d\n", sum);
	
	// 배열 0번 ~ 끝번 data 중 2의 배수, 3의 배수 삭제
	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
		}
		
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
			}
		}
	}
	
	// 배열 0번 ~ 끝번 data 순차로 출력
	if (LFirst(&list, &data)) {
		printf("2, 3의 배수 삭제된 데이터: %d", data);
		
		while (LNext(&list, &data)) {
			printf(" %d", data);
		}
	}
	
	puts("");
	
	return 0;
}