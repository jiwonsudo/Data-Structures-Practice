#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {  // from에 꽃힌 num개의 원반을 by를 거쳐 to로 이동
	if (num == 1) {
		printf("원반1을 %c에서 %c로 이동\n", from, to);  // 남은 원반이 하나인 경우 (탈출조건)
	} else {
		HanoiTowerMove(num - 1, from, to, by);  // 맨 아래의 원반을 제외한 나머지 원반(num-1개) 첫번째 기둥에서 두번째 기둥으로 이동
		printf("원반%d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);  // 
	}
}

void main() {
	HanoiTowerMove(3, 'A', 'B', 'C');
}