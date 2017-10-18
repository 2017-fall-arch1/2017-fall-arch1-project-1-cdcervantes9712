#ifndef bstree_included
#define bstree_included
/* Jorge Guijosa helped me understand some concepts of implementing a BST in C */

/* A Binary Search Tree node */
typedef struct BSTNode_s {
	struct BSTNode_s *left;
	struct BSTNode_s *right;
	char *str;
} BSTNode;

/* A list of BSTItems */
typedef struct {
	BSTNode *root;
} BSTree;

/* Create a new tree */
BSTree *bstAlloc();

/* Free memory associated with a tree, discarding all nodes it contains */
void bstFree(BSTree *tree);

/* Delete all elements off of the tree */
void bstMakeEmpty(BSTree *tree);

/* Removes all nodes of the tree recursively in post-order */
void emptyBst(BSTNode *node);

/* Insert to tree. Used llist demo files as reference. */
void bstAdd(BSTree *tree, char *name);

/* Print the strings of each node. If the tree is empty, prints a message. */
void bstPrint(BSTree *tree);

/* Recursive printing of the tree in order */
void recPrint(BSTNode *node);

/* Print to file */
void bstFilePrinter(BSTree *tree, FILE *file);

/* Recursive printing of the tree to a file */
void recFilePrinter(BSTNode *node, FILE *file);

/* Removes a node from the tree */
void bstDelete(BSTree *tree, char *name);

/* Recursively remove a node form a tree*/
BSTNode *recDelete(BSTNode *node, char *name);

/* Find minimum element in a tree*/
BSTNode *findMin(BSTNode *node);

#endif /* included */
