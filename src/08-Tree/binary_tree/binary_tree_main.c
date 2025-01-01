#include <stdio.h>
#include "binary_tree.h"

int main() {
	BTNode *bt1 = MakeBTNode();
	BTNode *bt2 = MakeBTNode();
	BTNode *bt3 = MakeBTNode();
	BTNode *bt4 = MakeBTNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	
	MakeLST(bt1, bt2);
	MakeRST(bt1, bt3);
	MakeLST(bt2, bt4);
	
	printf("%d\n", GetData(GetLST(bt1)));  // => 2
	printf("%d\n", GetData(GetLST(GetLST(bt1))));  // => 4
	
	return 0;
}