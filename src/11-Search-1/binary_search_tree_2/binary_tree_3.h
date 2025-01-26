#ifndef __BINARY_SEARCH_TREE_DELETION_H__
#define __BINARY_SEARCH_TREE_DELETION_H__

typedef int bt_data;

typedef struct BinaryTreeNode {
	bt_data data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
} BTNode;

BTNode *MakeBTNode(void);
bt_data GetData(BTNode *bt);
void SetData(BTNode *bt, bt_data data);

BTNode *GetLST(BTNode *bt);
BTNode *GetRST(BTNode *bt);

void MakeLST(BTNode *main, BTNode *sub);
void MakeRST(BTNode *main, BTNode *sub);

typedef void (*VisitFuncPtr)(bt_data data);

void PreTrav(BTNode *bt, VisitFuncPtr action);  // Preorder Traverse
void InTrav(BTNode *bt, VisitFuncPtr action);  // Inorder Traverse
void PostTrav(BTNode *bt, VisitFuncPtr action);  // Postorder Traverse

BTNode *RemoveLST(BTNode *bt);
BTNode *RemoveRST(BTNode *bt);

void ChangeLST(BTNode *main, BTNode *sub);
void ChangeRST(BTNode *main, BTNode *sub);

#endif