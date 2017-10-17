#include <stdio.h>

int main() {
	int n = 0;

	printf("To add a new employee, enter 1.\n");
	printf("To remove an employee, enter 2.\n");
	printf("To list all employees, enter 3.\n");
	printf("To exit, enter 9.\n");
	while (n != 1 || n != 2 || n != 3 || n != 9) {
		scanf("%d", &n);

		if(n == 1) {
			printf("You want to add.\n");
			break;
		} else if(n == 2) {
			printf("You want to remove.\n");
			break;
		} else if(n == 3) {
			printf("You want to display list.\n");
			break;
		} else if(n == 9) {
			printf("Goodbye!\n");
			exit(0);
		}else {
			printf("Wrong selection. Try again.\n");
		}
	}

	return 0;
}
