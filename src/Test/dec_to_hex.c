#include <stdio.h>

void decToHex(int dec, int arr[]) {
	int rem = 16;
	int i = 0;
	while (dec > 0) {
		rem = dec % 16;
		dec = dec / 16;  // int끼리의 나눗셈이므로 자동으로 몫으로 변환
		
		arr[i] = (rem < 10) ? '0' + rem : 'A' + (rem - 10);
		i++;
	}
}

void main() {
	int arr[100] = {0,}; 
	int dec = 72010265;
	
	decToHex(dec, arr);
	
	printf("DECIMAL: %d, HEXADECIMAL: ", dec);
	for (int i = 99; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	
	printf("\n");
}