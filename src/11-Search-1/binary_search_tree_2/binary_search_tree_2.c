#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_3.h"
#include "binary_search_tree_2.h"

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

BTNode *Remove(BTNode **p_root, bst_data target) {
	// the case where the deletion target is the root node must be separately considered.
	BTNode *pv_root = MakeBTNode();  // virtual root node
	BTNode *p_node = pv_root;  // parent node
	BTNode *c_node = *p_root;  // current node
	BTNode *d_node;  // delete d_node
	
	ChangeRST(pv_root, *p_root);
	
	// search target node
	while (c_node != NULL && GetData(c_node) != target) {
		p_node = c_node;
		if (target < GetData(c_node))
			c_node = GetLST(c_node);
		else
			c_node = GetRST(c_node);
	}
	
	if (c_node == NULL) return NULL;  // when target doesn't exist
	
	d_node = c_node;
	
	// 1st case: when target is terminal node
	if (GetLST(d_node) == NULL && GetRST(d_node) == NULL) {
		if (GetLST(p_node) == d_node)
			RemoveLST(p_node);
		else
			RemoveRST(p_node);
	}
	
	// 2nd case: when target has one child node
	else if (GetLST(d_node) == NULL || GetRST(d_node) == NULL) {
		BTNode *dc_node;  // points to child node of the target
		
		if (GetLST(d_node) != NULL) {
			dc_node = GetLST(d_node);
		} else {
			dc_node = GetRST(d_node);
		}
		
		if (GetLST(p_node) == d_node) {
			ChangeLST(p_node, dc_node);
		} else {
			ChangeRST(p_node, dc_node);
		}
	}
	
	// 3rd case: when target has both child nodes
	else {
		BTNode *m_node = GetRST(d_node);  // points to alternate node
		BTNode *mp_node = d_node;  // points to parent node of alt mp_node
		int del_data;
		
		while (GetLST(m_node) != NULL) {
			mp_node = m_node;
			m_node = GetLST(m_node);
		}
		
		// substitute the value stored in the alt node into the node to be deleted.
		del_data = GetData(d_node);  // backup data before substitute
		SetData(d_node, GetData(m_node));  // substitute
		
		// connect parent node of alt node and child d_node
		if (GetLST(mp_node) == m_node)
			ChangeLST(mp_node, GetRST(m_node));
		else
			ChangeRST(mp_node, GetRST(m_node));
		
		d_node = m_node;
		SetData(d_node, del_data);  // restore backup del_data
		
	}
	// additional handling for cases where the deleted node is the root node
	if (GetRST(pv_root) != *p_root)
		*p_root = GetRST(pv_root);

	free(pv_root);  // extinction of virtual root node
	return d_node;  // return target(deleted)
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void ShowAllData(BTNode *bst) {
	InTrav(bst, ShowIntData);
}