#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

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