#include <stdio.h>
#include "bin_tree_action.h"
#include "binary_search_tree.h"

void MakeAndInitBST(BTNode **p_root) {
	*p_root = NULL;
}

bst_data GetNodeData(BTNode *bst) {
	return GetData(bst);
}

void Insert(BTNode **p_root, bst_data data) {
	BTNode *parent_node = NULL;
	BTNode *curr_node = *p_root;
	BTNode *new_node = NULL;
	
	// find location to add new node
	while (curr_node != NULL) {
		
		// do not allow duplicate keys
		if (data == GetData(curr_node)) return;
		
		parent_node = curr_node;
		
		if (GetData(curr_node) > data) {
			curr_node = GetLST(curr_node);
		} else {
			curr_node = GetRST(curr_node);
		}
	}
		
	// generates new_node to be appended as a child of parent_node
	new_node = MakeBTNode();
	SetData(new_node, data);

	// append new node as parent_node's child
	if (parent_node != NULL) {  // if new_node is not root node
		if (data < GetData(parent_node)) {
			MakeLST(parent_node, new_node);
		} else {
			MakeRST(parent_node, new_node);
		}
	} else {  // else if new_node is root node
		*p_root = new_node;
	}
}

BTNode *Search(BTNode *bst, bst_data target) {
	BTNode *curr_node = bst;  // current node
	bst_data cd;  // current data
	
	while (curr_node != NULL) {
		cd = GetData(curr_node);
		
		if (target == cd) {
			return curr_node;
		} else if (target < cd) {
			curr_node = GetLST(curr_node);
		} else {
			curr_node = GetRST(curr_node);
		}
	}
	
	return NULL;
}