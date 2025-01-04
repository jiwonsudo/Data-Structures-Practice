#include <stdio.h>
#include <stdlib.h>
#include "bin_tree_delete.h"

BTNode* MakeBTNode(void) {
	BTNode *node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
}

bt_data GetData(BTNode *bt) {
	return bt->data;
}

void SetData(BTNode *bt, bt_data data) {
	bt->data = data;
}

BTNode* GetLST(BTNode *bt) {
	return bt->left;
}

BTNode *GetRST(BTNode *bt) {
	return bt->right;
}

void MakeLST(BTNode *main, BTNode *sub) {
	if(main->left != NULL) free(main->left);
	main->left = sub;
}

void MakeRST(BTNode *main, BTNode *sub) {
	if(main->right != NULL) free(main->right);
	main->right = sub;
}

void PreorderTraverse(BTNode *bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTNode *bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTNode *bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTNode *bt) {
	if(bt == NULL) return;
	
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	
	printf("Delete BTNode with its data %d.\n", bt->data);
	free(bt);
}