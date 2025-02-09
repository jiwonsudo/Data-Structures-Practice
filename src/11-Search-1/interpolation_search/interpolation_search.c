#include <stdio.h>

int InterpolationSearch(int arr[], int low, int high, int tgt, int *count) {
	(*count)++;
	if (arr[low] > tgt || arr[high] < tgt) return -1;  // 만약 시작수가 종료수보다 크다면 탐색 실패이므로 -1을 반환
	
	int mid = ((double)(tgt - arr[low]) / (arr[high] - arr[low]) * (high - low)) + low;  // 보간 탐색과 이진 탐색의 차이점
	
	if (arr[mid] == tgt) {
		return mid;
	} else if (arr[mid] > tgt) {  // 중앙값이 탐색목표보다 크다면 처음~중앙 재귀로 탐색
		return InterpolationSearch(arr, low, mid - 1, tgt, count);
	} else if (arr[mid] < tgt) {  // 중앙값이 탐색목표보다 작다면 중앙~끝 재귀로 탐색
		return InterpolationSearch(arr, mid + 1, high, tgt, count);
	}
}

int main() {
	int arr[] = {1, 3, 5, 6, 7, 8, 10, 12, 15, 16};
	int idx;
	int target = 5;
	int count = 0;
	
	idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target, &count);
	
	if (idx == -1) {
		printf("탐색 대상 '%d'이(가) 배열에 없음. 탐색횟수: %d\n", target, count);
	} else {	
		printf("탐색대상: %d, 탐색결과 인덱스: %d, 탐색횟수: %d\n", arr[idx], idx, count);
	}
	
	return 0;
}