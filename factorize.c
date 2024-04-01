#include <stdio.h>
#include <stdlib.h>

// Function to factorize a number
void factorize(int num) {
	int divisor = 2;
	while (num > 1) {
		while (num % divisor == 0) {
			printf("%d*", divisor);
			num /= divisor;
		}
		divisor++;
	}
}

int main(int argc, char *argv[]) {
	// Check if a filename is provided as an argument
	if (argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	// Open the file
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error opening file");
		return (1);
	}

	// Read each line from the file and factorize the numbers
	char buffer[100];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		int num = atoi(buffer);
		printf("%d=", num);
		factorize(num);
		printf("\n");
	}

	// Close the file
	fclose(file);
	return(0);
}
