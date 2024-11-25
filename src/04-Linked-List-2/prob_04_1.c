#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;  // 데이터 저장 변수
	struct _node *next  // 다음 노드 저장 변수 (Node형 구조체 변수의 주소 값 저장)
} Node;

int main() {
	Node *head = NULL;  // head 노드 (NULL로 초기화)
	Node *tail = NULL;  // tail 노드 (NULL로 초기화)
	Node *curr = NULL;  // curr 노드 (NULL로 초기화)
	
	Node *newNode = NULL;  // 새 노드 (NULL로 초기화)
	int readData;  // 데이터 임시저장 변수
	
	// Create data
	while(1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1) break;  // 읽은 데이터가 1보다 작으면 break
		
		// Create Node to create data
		newNode = (Node*)malloc(sizeof(Node));  // 새 노드를 동적할당
		newNode->data = readData;
		newNode->next = head;  // 새 노드의 다음 노드 저장 변수를 NULL로 초기화
		
		if (head == NULL)  // head 노드가 비었다면 newNode를 대입
			head = newNode;
		
		head = newNode;  // 어떠한 경우에도 tail에는 새 노드 대입
	}
	puts("");
	
	// Read data
	printf("입력 받은 데이터 전체 출력: ");
	if (head == NULL) {
		printf("저장된 데이터 없음");
	} else {
		curr = head;
		printf("%d ", curr->data);
		
		while (curr->next != NULL) {  // curr->next가 NULL이 아닐 경우 (배열의 끝이 아닐 때)
			curr = curr->next;
			printf("%d ", curr->data);
		}
	}
	puts(""); puts("");
	
	// Delete data (+free memory)
	if (head == NULL) {  // 삭제할 노드가 없다면
		return 0;
	} else {
		Node *delNode = head;
		Node *delNextNode = head->next;
		
		printf("데이터 %d를 삭제함.\n", head->data);
		free(delNode);  // 첫 번째 노드 삭제
		
		while (delNextNode != NULL) {  // 두 번째 이상 노드 삭제
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("데이터 %d를 삭제함.\n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}