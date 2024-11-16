// 재귀함수 연습
#include <stdio.h>

int sumFrom0(int number);

void main() {
	int numberToSum = 10;
	printf("0에서 %d까지의 합: %d\n", numberToSum, sumFrom0(numberToSum));
}

// 재귀함수
int sumFrom0(int number) {
	if (number > 0) {  // 재귀함수에는 탈출 조건이 있어야 함
		return number + sumFrom0(number - 1);  // 함수를 재호출
	} else {
		return number;  // 탈출 시
	}
}