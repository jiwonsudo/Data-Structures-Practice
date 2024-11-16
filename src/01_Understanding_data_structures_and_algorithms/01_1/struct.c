// 구조체 기본 사용법
#include <stdio.h>

struct Book
{
	char title[50]; // 배열의 크기는 문자 byte수 + 1(null문자열), 한글은 문자 1개당 2byte
	char author[50];
	int price;
};

// int main()
// {
// 	struct Book MyBook = {.title = "윤성우의 열혈 자료구조", .author = "윤성우", .price = 27000};
	
// 	printf("책 제목: %s\n저자: %s\n가격:%d\n", MyBook.title, MyBook.author, MyBook.price);
// 	return 0;
// }


// typedef 사용법
typedef struct Book Book; // 이 경우 'struct인 Book'을 Book로 명명 가능

// 또는 아예 구조체 선언 시 아래와 같이 한번에 명명 가능
// typedef struct Book
// {
// 	char title[50];
// 	char author[50];
// 	int price;
// }Book;

int main()
{
	Book MyBook = {"정지원 자서전", "정지원", 20040206};
	printf("책 제목: %s\n저자: %s\n가격:%d\n", MyBook.title, MyBook.author, MyBook.price);
	return 0;
}