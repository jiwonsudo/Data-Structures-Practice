#include "AppendDecToHex.h"
#include <stdio.h>

void main() {
	int arr[100] = {0,}; 
	int dec = 72010265;
	
	AppendDecToHex(dec, arr);
	
	printf("DECIMAL: %d, HEXADECIMAL: ", dec);
	for (int i = 99; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	
	printf("\n");
}