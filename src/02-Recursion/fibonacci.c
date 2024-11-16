#include <stdio.h>

int Fib(int n) {
	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else {
		return Fib(n - 1) + Fib(n - 2);
	}
}

void main() {
	int num;
	
	printf("Input length of array: ");
	scanf("%d", &num);
	
	for(int i = 1; i <= num; i++) {
		printf("%d ", Fib(i));
	}
}




