#include <stdio.h>

void SelectionSort(int arr[], int len) {
	int maxIdx;
	int temp;
	
	for (int i = 0; i < len - 1; i++) {
		maxIdx = i;  // maxIdx 초기화 (기탐색 값 제외)
		for (int j = i + 1; j < len; j++) {  // 최솟값 탐색
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main() {
	int arr[4] = {3, 4, 2, 1};
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	
	puts("");
	return 0;
}