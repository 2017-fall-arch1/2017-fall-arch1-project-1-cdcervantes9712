#ifndef bstree_included
#define bstree_included

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
void emptyBst(BSTNode *root);

/* Insert to tree. Used llist demo files as reference. */
void bstAdd(BSTree *tree, char *str);

/* Print the strings of each node. If the tree is empty, prints a message. */
void bstPrint(BSTree *tree);

/* Recursive printing of the tree in order */
void recPrint(BSTNode *root);

/* Print to file */
void bstPrintToFile(BSTree *tree, FILE *fp);

/* Recursive printing of the tree to a file */
void recPrintToFile(BSTNode *root, FILE *fp);

/* Removes a node from the tree */
void bstRemove(BSTree *tree, char *removee);

/* Recursively remove a node form a tree*/
BSTNode *recursiveRemove(BSTNode *root, char *removee);

/* Find minimum element in a tree*/
BSTNode *findMin(BSTNode *root);

#endif /* included */
