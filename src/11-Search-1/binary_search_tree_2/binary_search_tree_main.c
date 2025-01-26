#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree_2.h"

int main(void) {
	BTNode *bst_root;
	BTNode *s_node;
	
	MakeAndInitBST(&bst_root);
	
	int arr[9] = {5, 8, 1, 6, 4, 9, 3, 2, 7};
	
	for (int i = 0; i <= 8; i++) {
		Insert(&bst_root, arr[i]);
	}
	
	ShowAllData(bst_root); puts("");
	s_node = Remove(&bst_root, 3);
	free(s_node);
	
	ShowAllData(bst_root); puts("");
	s_node = Remove(&bst_root, 8);
	free(s_node);
	
	ShowAllData(bst_root); puts("");
	s_node = Remove(&bst_root, 1);
	free(s_node);
	
	ShowAllData(bst_root); puts("");
	s_node = Remove(&bst_root, 6);
	free(s_node);
	
	ShowAllData(bst_root); puts("");
	return 0;
}