#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int bt_data;

typedef struct BinaryTreeNode {
	bt_data data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
} BTNode;

BTNode* MakeBTNode(void);
bt_data GetData(BTNode *bt);
void SetData(BTNode *bt, bt_data data);

// LST: Left SubTree, RST: Right SubTree

BTNode* GetLST(BTNode *bt);  
BTNode* GetRST(BTNode *bt);

void MakeLST(BTNode *main, BTNode *sub);
void MakeRST(BTNode *main, BTNode *sub);

typedef void (*VisitFuncPtr)(bt_data data);

void PreorderTraverse(BTNode *bt, VisitFuncPtr action);
void InorderTraverse(BTNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTNode *bt, VisitFuncPtr action);

#endif