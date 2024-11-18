#ifndef __APPENDDECTOHEX__
# define __APPENDDECTOHEX__

#include <stdio.h>

void AppendDecToHex(int dec, int arr[]) {
	int rem = 16;
	int i = 0;
	while (dec > 0) {
		rem = dec % 16;
		dec = dec / 16;  // int끼리의 나눗셈이므로 자동으로 몫으로 변환
		
		arr[i] = (rem < 10) ? '0' + rem : 'A' + (rem - 10);
		i++;
	}
}

#endif