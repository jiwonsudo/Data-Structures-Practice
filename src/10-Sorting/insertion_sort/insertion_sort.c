#include <stdio.h>

void InsertionSort(int arr[], int len) {
	int insert_data;
	
	for (int i = 1; i < len; i++) {
		insert_data = arr[i];
		int j;
		for(j = i - 1; j >= 0; j--) {  // 앞으로 한칸씩 이동하며 비교
			if (arr[j] > insert_data) {
				arr[j + 1] = arr[j];  // 비교대상 뒤로 한칸 밀기 (앞장서기)
			} else break;  // 삽입위치 찾으면 탈출
		}
		
		arr[j + 1] = insert_data;
	}
}

int main() {
	int arr[5] = {5, 3, 2, 4, 1};
	
	InsertionSort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	
	puts("");
	return 0;
}