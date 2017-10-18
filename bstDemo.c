#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
BSTree *employeetree(BSTree *tree);
BSTree *initializetree(BSTree *tree);

/* User interface for input and output of BST contents. */
BSTree *employeetree(BSTree *tree) {
	int n = 0;
	char name[256];

	printf("To add a new employee, enter 1.\n");
	printf("To remove an employee, enter 2.\n");
	printf("To list all employees, enter 3.\n");
	printf("To exit, enter 9.\n");

	while (n != 1 || n != 2 || n != 3 || n != 9) {
		scanf("%d", &n);

		if(n == 1) {
			system("cls");
			printf("Enter the name of the employee to add.\n");
			scanf("%s", name);
			bstAdd(tree, name);
			return tree;

		} else if(n == 2) {

			system("cls");
			printf("Enter the name of the employee to remove.\n");
			scanf("%s", name);
			bstDelete(tree, name);
			return tree;

		} else if(n == 3) {

			system("cls");
			printf("List of employees is as follows:\n");
			bstPrint(tree);
			return tree;

		} else if(n == 9) {

			system("cls");
			return tree;

		}else {
			printf("Wrong selection. Try again.\n");
		}
	}
	return tree;
}

/* Gets names from a txt file and populates the BST with those names. */
BSTree *initializetree(BSTree *tree) {
	char const* const fileName = "names.txt";
	FILE* file = fopen(fileName, "r");
	char line[256];

	while (fgets(line, sizeof(line), file)) {
		line[strlen(line) - 1] = 0;
		bstAdd(tree, line);
	}

	fclose(file);
	return tree;
}

int main() {
	char choice;
	BSTree *tree = bstAlloc();
	tree = initializetree(tree);
	bstPrint(tree);
	employeetree(tree);

	FILE * file = fopen("names.txt", "w");
	bstFilePrinter(tree, file);
	fclose(file);

	while(choice != 'n' || choice != 'y') {
		printf("Would you like to perform any other operation? (y/n)\n");
		scanf(" %c", &choice);
		if(choice == 'n') {
			printf("Goodbye!\n");
			exit(0);
		} else if (choice == 'y') {
			system("cls");
			employeetree(tree);
			file = fopen("names.txt", "w");
			bstFilePrinter(tree, file);
			fclose(file);
			continue;
		} else {
			system("cls");
			printf("Wrong selection. Please try again.\n");
		}
	}
	return 0;
}
