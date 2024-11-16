#ifndef __MYFUNCS__  // 만약 __MYFUNCS__ 정의 되어 있지 않으면
# define __MYFUNCS__  // __MYFUNCS__ 매크로를 정의한다 (헤더파일 중복을 막기 위해 사용)

# include <stdio.h>  // 여기서 사용할 헤더 파일

void printLikePython(char charArr[]) {
	printf("%s\n", charArr);
}

#endif  // __MYFUNCS__ 매크로 정의의 끝