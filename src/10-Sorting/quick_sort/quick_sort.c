#include <stdio.h>

void SwapElements(int arr[], int idx_of_first_elem, int idx_of_second_elem) {
	int temp = arr[idx_of_first_elem];
	arr[idx_of_first_elem] = arr[idx_of_second_elem];
	arr[idx_of_second_elem] = temp;
}

int SortAndGetPivot(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	
	while (low <= high) {
		while (pivot >= arr[low] && low <= right) low++;
		while (pivot <= arr[high] && high >= left + 1) high--;
		if (low <= high) SwapElements(arr, low, high);
		
	}
		SwapElements(arr, left, high);  // Swap data pointed to by pivot & high
		return high;  // return moved pivot's position info
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = SortAndGetPivot(arr, left, right);
		QuickSort(arr, left, pivot - 1);  // sort left area
		QuickSort(arr, pivot + 1, right);  // sort right area
	}
}

int main() {
	int arr[9] = {3, 2, 3, 3, 4, 1, 7, 6, 5};
	
	int len = sizeof(arr)/ sizeof(int);
	
	QuickSort(arr, 0, len - 1);
	
	for (int i = 0; i < len; i++) printf("%d ", arr[i]);
	puts("");
	
	return 0;
}