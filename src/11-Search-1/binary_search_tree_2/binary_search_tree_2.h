#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "binary_tree_3.h"

typedef bt_data bst_data;

// make Binary Search Tree and initialize
void MakeAndInitBST(BTNode **p_root);

// returns data saved in node
bst_data GetNodeData(BTNode *bst);

// saves data to BST(includes generating node)
void Insert(BTNode **p_root, bst_data data);

// search data in BST
BTNode *Search(BTNode *bst, bst_data target);

// feat: remove node from tree and return its address value
BTNode *Remove(BTNode **p_root, bst_data target);

#endif