#include <stdio.h>
#include "binary_search_tree.h"

int main() {
	BTNode *bst_root;
	BTNode *search_node;
	
	MakeAndInitBST(&bst_root);
	
	Insert(&bst_root, 9);
	Insert(&bst_root, 1);
	Insert(&bst_root, 6);
	Insert(&bst_root, 2);
	Insert(&bst_root, 8);
	Insert(&bst_root, 3);
	Insert(&bst_root, 5);
	
	search_node = Search(bst_root, 1);
	if (search_node == NULL) {
		printf("Search failed. \n");
	} else {
		printf("Value of successfully searched key: %d \n", GetNodeData(search_node));
	}
	
	search_node = Search(bst_root, 4);
	if (search_node == NULL) {
		printf("Search failed. \n");
	} else {
		printf("Value of successfully searched key: %d \n", GetNodeData(search_node));
	}
	
	search_node = Search(bst_root, 6);
	if (search_node == NULL) {
		printf("Search failed. \n");
	} else {
		printf("Value of successfully searched key: %d \n", GetNodeData(search_node));
	}
	
	search_node = Search(bst_root, 7);
	if (search_node == NULL) {
		printf("Search failed. \n");
	} else {
		printf("Value of successfully searched key: %d \n", GetNodeData(search_node));
	}
	
	return 0;
}