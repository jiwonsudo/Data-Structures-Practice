// 포인터
#include <stdio.h>

int main()
{
	int numberForTest = 9292;
	// 포인터 선언
	int *ptr = &numberForTest; // ptr은 4byte의 int인 numberForTest가 저장된 메모리 영역의 주소값을 저장
	int *pptr = &ptr; // pptr은 포인터 ptr의 메모리 주소값을 저장 = 포인터 참조
		
	printf("숫자: %d\n숫자의 주소값(ptr):%p\n숫자의 주소값의 주소값(pptr):%p\n", numberForTest, ptr, pptr);
	
	return 0;
}