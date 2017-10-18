#include <stdio.h>             /* for puts */
#include <stdlib.h>            /* for malloc */
#include <assert.h>            /* for assert */
#include <string.h>            /* for strcmp */
#include <ctype.h>             /* for tolower */
#include <stdio.h>             /* for input output ops*/
#include "bstree.h"

/* Create a new tree */
BSTree *bstAlloc() {
	BSTree *tree = (BSTree *) malloc(sizeof(BSTree));
	tree->root = 0;
	return tree;
}

/* Free memory associated with a tree, discarding all nodes it contains */
void bstFree(BSTree *tree) {
	bstMakeEmpty(tree);
	free(tree);
	tree = 0;
}

/* Delete all elements off of the tree */
void bstMakeEmpty(BSTree *tree) {
	BSTNode *node = tree->root;
	emptyBst(node);
	tree->root = 0;
}

/* Removes all nodes of the tree recursively in post-order */
void emptyBst(BSTNode *node) {
	if(node == 0) {
		return;
	}
	emptyBst(node->left);
	node->left = 0;
	emptyBst(node->right);
	node->right = 0;
	free(node->str);
	free(node);
}

/* Insert to tree. Used llist demo files as reference. */
void bstAdd(BSTree *tree, char *name) {
	int sLen,i;
	char inserted = 0;
	char *copy;
	BSTNode *insertee, *checker = tree->root;
	/* compute length of the string */
	for (i = 0; name[i]; i++){
		name[i] = tolower(name[i]);
	}
	for (sLen = 0; name[sLen]; sLen++);
	copy = (char *) malloc(sLen+1);
	/* copy input string into copy variable */
	for (sLen = 0; name[sLen]; sLen++){
		copy[sLen] = name[sLen];
	}
	copy[sLen] = 0;

	/* Allocate memory for the new node */
	insertee = (BSTNode *) malloc(sizeof(BSTNode));
	insertee->str = copy;
	insertee->left = 0;
	insertee->right = 0;

	if(tree->root == 0){
		tree->root = insertee;
		return;
	}
	/* Append to where it belongs */
	while(!inserted){
		if(strcmp(checker->str, insertee->str) > 0){
			if(!checker->left){
				checker->left = insertee;
				inserted = 1;
			}
			else{
				checker = checker->left;
			}
		}
		else if(strcmp(checker->str, insertee->str) <0){
			if(!checker->right){
				checker->right =insertee;
				inserted = 1;
			}
			else{
				checker = checker->right;
			}
		}
		else{
			puts("Name already registered. Employee not added.\n");
			inserted = 1;
		}
	}
}

/* Print the strings of each node. If the tree is empty, prints a message. */
void bstPrint(BSTree *tree) {
	if(tree->root == 0){
		puts("There are no employees to display.\n");
	}
	else{
		recPrint(tree->root);
		puts("\n");
	}
}

/* Recursive printing of the tree in order */
void recPrint(BSTNode *node) {
	BSTNode *visit;
	if(node == 0){
		return;
	}
	else{
		recPrint(visit = node->left);
		printf("- %s\n", node->str);
		recPrint(visit = node->right);
	}
}

/* Print to file */
void bstFilePrinter(BSTree *tree, FILE *file) {
	if(tree->root == 0) {
		fputs("There are no employees to display.\n", file);
	}
	else{
		recFilePrinter(tree->root,file);
		fputs("\n",file);
	}
}
/* Recursive printing of the tree to a file */
void recFilePrinter(BSTNode *node, FILE *file) {
	if(node == 0){
		return;
	}
	else{
		fprintf(file,"%s\n",node->str);
		recFilePrinter(node->left,file);
		recFilePrinter(node->right,file);
	}
}

/* Removes a node from the tree */
void bstDelete(BSTree *tree, char *name) {
	BSTNode *node = tree->root;
	recDelete(node, name);
}

/* Recursively remove a node form a tree*/
BSTNode *recDelete(BSTNode *node, char *name) {
	if(node == 0){
		puts("Employee not found");
		return node;
	}
	int cmpRes = (strcmp(node->str, name));
	if (cmpRes > 0){
		node->left = recDelete(node->left, name);
	}
	else if(cmpRes < 0){
		node->right = recDelete(node->right, name);
	}
	else if((node->left != 0) && (node->right != 0)){
		node->str = findMin(node->right)->str;
		puts("removing less of drive");
		node->right = recDelete(node->right, node->str);
	}
	else{
		if(node->left != 0) {
			BSTNode *temp = node;
			node = node->left;
			free(temp->str);
			free(temp);
		}
		else{
			BSTNode *temp = node;
			node = node->right;
			free(temp->str);
			free(temp);
		}
	}
	return node;
}

/* Find minimum element in a tree*/
BSTNode *findMin(BSTNode *node) {
	while(node->left){
		node = node->left;
	}
	return node;
}
