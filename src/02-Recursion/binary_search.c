#include <stdio.h>

int BinSearch(int arr[], int start, int end, int tgt, int *count) {
	(*count)++;
	if (start > end) return -1;  // 만약 시작수가 종료수보다 크다면 탐색 실패이므로 -1을 반환
	int mid = (start + end) / 2;
	if (arr[mid] == tgt) {
		return mid;
	} else if (arr[mid] > tgt) {  // 중앙값이 탐색목표보다 크다면 처음~중앙 재귀로 탐색
		return BinSearch(arr, start, mid - 1, tgt, count);
	} else if (arr[mid] < tgt) {  // 중앙값이 탐색목표보다 작다면 중앙~끝 재귀로 탐색
		return BinSearch(arr, mid + 1, end, tgt, count);
	}
}

void main() {
	int arr[] = {1, 3, 5, 6, 7, 8, 10, 12, 15, 16};
	int idx;
	int target = 5;
	int count = 0;
	
	idx = BinSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target, &count);
	
	if (idx == -1) {
		printf("탐색 대상 '%d'이(가) 배열에 없음. 탐색횟수: %d\n", target, count);
	} else {	
		printf("탐색대상: %d, 탐색결과 인덱스: %d, 탐색횟수: %d\n", arr[idx], idx, count);
	}
}