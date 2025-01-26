#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_3.h"

BTNode *MakeBTNode(void) {
	BTNode *node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}

bt_data GetData(BTNode *bt) { return bt->data; }
void SetData(BTNode *bt, bt_data data) { bt->data = data; }
BTNode *GetLST(BTNode *bt) { return bt->left; }
BTNode *GetRST(BTNode *bt) { return bt->right; }

void MakeLST(BTNode *main, BTNode *sub) {
	if (main->left != NULL) free(main->left);
	main->left = sub;
}

void MakeRST(BTNode *main, BTNode *sub) {
	if (main->right != NULL) free(main->right);
	main->right = sub;
}

void PreTrav(BTNode *bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	action(bt->data);
	PreTrav(bt->left, action);
	PreTrav(bt->right, action);
}

void InTrav(BTNode *bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	InTrav(bt->left, action);
	action(bt->data);
	InTrav(bt->right, action);
}

void PostTrav(BTNode *bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	PostTrav(bt->left, action);
	PostTrav(bt->right, action);
	action(bt->data);
}

BTNode *RemoveLST(BTNode *bt) {
	BTNode *del_node;
	if (bt != NULL) {
		del_node = bt->left;
		bt->left = NULL;
	}
	return del_node;
}

BTNode *RemoveRST(BTNode *bt) {
	BTNode *del_node;
	if (bt != NULL) {
		del_node = bt->right;
		bt->right = NULL;
	}
	return del_node;
}

void ChangeLST(BTNode *main, BTNode *sub) { main->left = sub; }
void ChangeRST(BTNode *main, BTNode *sub) { main->right = sub; }