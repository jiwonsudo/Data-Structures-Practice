#include <stdio.h>
#include "binary_tree.h"

void InOrderTraverse(BTNode *bt) {
	if(bt == NULL) return;  // recursion escape condition
	
	InOrderTraverse(bt->left);  // recurse left tree
	printf("%d\n", bt->data);  // print root node's data
	InOrderTraverse(bt->right);  // recurse right tree
}

void PreOrderTraverse(BTNode *bt) {
	if(bt == NULL) return;
	
	printf("%d\n", bt->data);
	PreOrderTraverse(bt->left);
	PreOrderTraverse(bt->right);
}

void PostOrderTraverse(BTNode *bt) {
	if(bt == NULL) return;
	
	PostOrderTraverse(bt->left);
	PostOrderTraverse(bt->right);
	printf("%d\n", bt->data);
}

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
	
	InOrderTraverse(bt1);
	
	return 0;
}