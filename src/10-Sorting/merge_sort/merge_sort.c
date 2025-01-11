#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int front_start_idx = left;
	int back_start_idx = mid + 1;
	
	int *sort_arr = (int*)malloc(sizeof(int) * (right + 1));
	int start_idx = left;
	
	while (front_start_idx <= mid && back_start_idx <= right) {
		sort_arr[start_idx] = arr[front_start_idx] <= arr[back_start_idx]? arr[front_start_idx++] : arr[back_start_idx++];
		start_idx++;
	}
	
	if (front_start_idx > mid) {
		for (int i = back_start_idx; i <= right; i++, start_idx++)
			sort_arr[start_idx] = arr[i];
	} else {
		for (int i = front_start_idx; i <= mid; i++, start_idx++)
			sort_arr[start_idx] = arr[i];
	}
	
	for (int i = left; i <= right; i++) {
		arr[i] = sort_arr[i];
	}
	
	free(sort_arr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	
	if (left < right) {
		mid = (left + right) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		
		MergeTwoArea(arr, left, mid, right);
	}
}

int main() {
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	
	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	
	puts("");
	return 0;
}