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
	BSTNode *root = tree->root;
	emptyBst(root);
	tree->root = 0;
}

/* Removes all nodes of the tree recursively in post-order */
void emptyBst(BSTNode *root) {
	if(root == 0){
		return;
	}
	emptyBst(root->left);
	root->left = 0;
	emptyBst(root->right);
	root->right = 0;
	free(root->str);
	free(root);
}

/* Insert to tree. Used llist demo files as reference. */
void bstAdd(BSTree *tree, char *str) {
	int sLen,i;
	char inserted = 0;
	char *copy;
	BSTNode *insertee, *checker = tree->root;
	/* compute length of the string */
	for (i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
	for (sLen = 0; str[sLen]; sLen++);
	copy = (char *) malloc(sLen+1);
	/* copy input string into copy variable */
	for (sLen = 0; str[sLen]; sLen++){
		copy[sLen] = str[sLen];
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
void recPrint(BSTNode *root) {
	BSTNode *visit;
	if(root == 0){
		return;
	}
	else{
		recPrint(visit = root->left);
		printf("<%s>\n",root->str);
		recPrint(visit = root->right);
	}
}

/* Print to file */
void bstPrintToFile(BSTree *tree, FILE *fp) {
	if(tree->root == 0){
		fputs("There are no employees to display.\n", fp);
	}
	else{
		recPrintToFile(tree->root,fp);
		fputs("\n",fp);
	}
}
/* Recursive printing of the tree to a file */
void recPrintToFile(BSTNode *root, FILE *fp) {
	if(root == 0){
		return;
	}
	else{
		fprintf(fp,"%s\n",root->str);
		recPrintToFile(root->left,fp);
		recPrintToFile(root->right,fp);
	}
}

/* Removes a node from the tree */
void bstRemove(BSTree *tree, char *removee) {
	BSTNode *root = tree->root;
	recursiveRemove(root,removee);
}

/* Recursively remove a node form a tree*/
BSTNode *recursiveRemove(BSTNode *root, char *removee) {
	if(root == 0){
		puts("Not found");
		return root;
	}
	int cmpRes = (strcmp(root->str,removee));
	if (cmpRes > 0){
		root->left = recursiveRemove(root->left,removee);
	}
	else if(cmpRes < 0){
		root->right = recursiveRemove(root->right,removee);
	}
	else if((root->left != 0) && (root->right != 0)){
		root->str = findMin(root->right)->str;
		puts("removing less of drive");
		root->right = recursiveRemove(root->right, root->str);
	}
	else{
		if(root->left != 0){
			BSTNode *temp = root;
			root = root->left;
			free(temp->str);
			free(temp);
		}
		else{
			BSTNode *temp = root;
			root = root->right;
			free(temp->str);
			free(temp);
		}
	}
	return root;
}

/* Find minimum element in a tree*/
BSTNode *findMin(BSTNode *root) {
	while(root->left){
		root = root->left;
	}
	return root;
}
