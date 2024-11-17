#include <stdio.h>

void main() {
	int dec = 72010265;
	int rem = 16;
	int arr[100] = {0,}; 
	
	for(int i = 0; dec > 0; i++) {
		rem = dec % 16;
		dec = dec / 16;  // int끼리의 나눗셈이므로 자동으로 몫으로 변환
		arr[i] = rem;
		
	}
	
	printf("DECIMAL: %d, HEXADECIMAL: ", dec);
	int isEmptyArr = 1;
	
	for (int i = 99; i >= 0; i--) {
		if (arr[i] != 0) {
			isEmptyArr = 0;
		}
		if (isEmptyArr == 0) {
			switch (arr[i]) {
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default:
				printf("%d", arr[i]);
				break;
			}
		}
	}
	
	printf("\n");
}