#include <stdio.h>
#include "bin_tree_action.h"

void ShowIntData(int data) {
	printf("%d ", data);
}

int main() {
	BTNode *bt1 = MakeBTNode();
	BTNode *bt2 = MakeBTNode();
	BTNode *bt3 = MakeBTNode();
	BTNode *bt4 = MakeBTNode();
	BTNode *bt5 = MakeBTNode();
	BTNode *bt6 = MakeBTNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	
	MakeLST(bt1, bt2);
	MakeRST(bt1, bt3);
	MakeLST(bt2, bt4);
	MakeRST(bt2, bt5);
	MakeRST(bt3, bt6);
	
	PreorderTraverse(bt1, ShowIntData);
	puts("");
	InorderTraverse(bt1, ShowIntData);
	puts("");
	PostorderTraverse(bt1, ShowIntData);
	puts("");
}