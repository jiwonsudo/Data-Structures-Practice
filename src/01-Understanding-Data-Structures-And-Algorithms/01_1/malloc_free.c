// 동적할당함수(malloc, free) 연습
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array1[5] = {15, 25, 35, 45, 55};  // 일반 배열
	int *array2 = (int*)malloc(sizeof(int) * 5);  // malloc 함수로 동적 생성한 20byte(int(4byte)*5) 크기의 배열 (배열의 첫 주소 = 배열 = 포인터가 가리키는 주소)
	
	for(int i = 0; i < 5; i++) {
		array2[i] = array1[i];
		printf("%d\n", array2[i]);
	}
	
	free(array2);  // 할당된 메모리 해제
	
	return 0;
}