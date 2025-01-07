#include <stdio.h>

void BubbleSort(int arr[], int len) {
	int i, j;
	int temp;
	
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < (len - i) - 1; j++) {  // i가 1 증가할수록 배열의 뒤부터 1 인덱스씩 정렬되므로, 뒷부분은 비교가 필요없음
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[4] = {3, 2, 4, 1};
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	
	puts("");
	return 0;
}